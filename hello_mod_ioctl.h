/*
 * ==================================================================================
 * filename:  hello_mod_ioctl.h 
 * 
 *    Description:  define the cmd supported by hello_mod 
 * 
 *        Version:  1.0 
 *        Created:  
 *       Revision:  none 
 *       Compiler:  gcc 
 * 
 *         Author:  
 *        Company:   
 * 
 * ===================================================================================== 
 */  
  
#ifndef __HELLO_MOD_IOCTL_H__  
#define __HELLO_MOD_IOCTL_H__  
  
#define HELLO_MAGIC    12  
#define HELLO_IOCTL_RESETLANG    _IO(HELLO_MAGIC,0)        //set langtype = english  
#define HELLO_IOCTL_GETLANG        _IOR(HELLO_MAGIC,1,int)    //get langtype  
#define HELLO_IOCTL_SETLANG        _IOW(HELLO_MAGIC,2,int)    //set langtype  
  
typedef enum _lang_t  
{  
    english, chinese, pinyin  
}lang_t;  
  
#endif  
