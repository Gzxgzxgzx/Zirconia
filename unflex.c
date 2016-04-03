#include <errno.h>
#include <fcntl.h>     // open()
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <net/if.h>
#include <net/if_arp.h>
#include <sys/ioctl.h>
#include <sys/types.h> // Not technically required by fcntl.h,
#include <sys/stat.h>  // but needed on some distributions

const char const * IF_NAME = "eth0";

int main( void ) {
  struct ifreq ifr;
  const unsigned char *hw_addr;
  size_t if_name_len;

  if_name_len = strlen( IF_NAME );
  if ( if_name_len < sizeof(ifr.ifr_name) ) {
    memcpy( ifr.ifr_name, IF_NAME, if_name_len);
    ifr.ifr_name[if_name_len] = 0;
  } else {
    fprintf( stderr, "main(): could not write iface name (!)\n");
    return 1;
  }

  int fd = socket( AF_UNIX, SOCK_DGRAM, 0 );
  if ( fd == -1 ) {
    int tmp_errno = errno;
    fprintf( stderr, "main(): %s (!)\n", strerror(tmp_errno) );
    return 1;
  }

  if ( ioctl(fd, SIOCGIFHWADDR, &ifr) == -1 ) {
    int tmp_errno = errno;
    fprintf( stderr, "main(): %s (!)\n", strerror(tmp_errno) );
    close( fd );
    return 1;
  }

  printf( "HOSTID: %lX\n", gethostid());
  hw_addr = (unsigned char*)ifr.ifr_hwaddr.sa_data;
  printf( "hw_addr: %02X:%02X:%02X:%02X:%02X:%02X:\n",
    hw_addr[0], hw_addr[1], hw_addr[2], hw_addr[3], hw_addr[4], hw_addr[5]);

  close( fd );

  return 0;
}
