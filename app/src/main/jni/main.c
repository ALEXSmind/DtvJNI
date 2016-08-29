#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include "com_example_n1_dtvjni_MainActivity.h"


#define SPI_TUNER_POWER_OFF 0x00
#define SPI_TUNER_POWER_ON 0x01

#define SW_TO_DTV_WW	0x00
#define SW_TO_FM		0x01
#define SW_TO_DTV_TW_JP	0x02

#define SPI_IOC_MAGIC			'k'
#define SPI_IOC_WR_TUNER_POWER _IOW(SPI_IOC_MAGIC,6,__u8)
#define SPI_IOC_WR_DTV_FM_SWITCH _IOW(SPI_IOC_MAGIC,7,__u8)

/*
 * Class:     com_example_n1_dtvjni_MainActivity
 * Method:    switch_to
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_com_example_n1_dtvjni_MainActivity_switch_1to
  (JNIEnv *env, jobject jobj, jint i){

    jint ret = 0;
    int fd = 0;
	int arg = 0;
    printf("zjd, ioctl  test... ...\n");

    //open module
    fd = open("/dev/spidtv", O_RDWR);
    if (fd < 0)
    {
        printf("ioctl test error retcode = %d\n", fd);
        ret = -1;
    }

    switch (i) {
	case SW_TO_DTV_WW:
        arg = SW_TO_DTV_WW;
        ret = (jint)ioctl(fd, SPI_IOC_WR_DTV_FM_SWITCH,&arg);
		break;
	case SW_TO_FM:
        arg = SW_TO_FM;
        ret = (jint)ioctl(fd, SPI_IOC_WR_DTV_FM_SWITCH,&arg);
		break;
	case SW_TO_DTV_TW_JP:
        arg = SW_TO_DTV_TW_JP;
        ret = (jint)ioctl(fd, SPI_IOC_WR_DTV_FM_SWITCH,&arg);
		break;
	default:
	    ret = -1;
	    printf("ioctl test SPI_IOC_WR_DTV_FM_SWITCH no such case\n");
	    break;
    }

    if (ret < 0)
    {
		printf("ioctl test SPI_IOC_WR_DTV_FM_SWITCH error retcode = %d\n", ret);
	}
	close(fd);
    return ret;

  }



/*
 * Class:     com_example_n1_dtvjni_MainActivity
 * Method:    power_control
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_com_example_n1_dtvjni_MainActivity_power_1control
  (JNIEnv *env, jobject jobj, jint i){

    jint ret = 0;
    int fd = 0;
	int arg = 0;
    printf("zjd, ioctl  test... ...\n");

    //open module
    fd = open("/dev/spidtv", O_RDWR);
    if (fd < 0)
    {
        printf("ioctl test error retcode = %d\n", fd);
        ret = -1;
    }

    switch (i) {
	case SPI_TUNER_POWER_OFF:
        arg = SPI_TUNER_POWER_OFF;
        ret = (jint)ioctl(fd, SPI_IOC_WR_TUNER_POWER,&arg);
		break;
	case SPI_TUNER_POWER_ON:
        arg = SPI_TUNER_POWER_ON;
        ret = (jint)ioctl(fd, SPI_IOC_WR_TUNER_POWER,&arg);
		break;
	default:
	    ret = -1;
	    printf("ioctl test SPI_IOC_WR_TUNER_POWER no such case\n");
	    break;
    }

    if (ret < 0)
    {
		printf("ioctl test SPI_IOC_WR_TUNER_POWER error retcode = %d\n", ret);
	}
	close(fd);
    return ret;
  }

