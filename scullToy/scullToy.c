/* ============================================================================
 * Breakable Toy of Char Device Driver Exevise
 * 
 * Reference to Ch3 in Linux Device Driver 3rd
 * This device only considers the basic operation of Char Device Driver,
 * so advanced functions such as ioctl are not shown here.
 * ============================================================================*/

// ======================= Basic kernel and module header =======================
#include <linux/kernel.h>	//Function printk()
#include <linux/module.h>
#include <linux/types.h>	//size_t 
// ======================= Essential Device Driver Include  =====================
#include <linux/fs.h>		
#include <linux/init.h>		//Module Init API
#include <linux/cdev.h>		//Char Device API

#define DEVICE_NAME	"scullToy"

struct cdev cdev_Toy;
int scullToy_major;
int scullToy_minor =	0;
int scullToy_TotalNum =	1;

/* ============================================================================
 * Char Device Operation Definition & Implementation
 *   |- Only four required operations are implemented here:
 *     |- open, release, read, write
 * ============================================================================*/

static int scullToy_open(struct inode *inode, struct file *filp)
{
	return 0;
}
static int scullToy_release(struct inode *inode, struct file *filp)
{
	return 0;
}
static ssize_t scullToy_read(struct file *filp, char __user *buff, size_t count, loff_t *f_ops)
{
	return 0;
}
static ssize_t scullToy_write(struct file *flip, const __user *buff, size_t count, loff_t *f_ops)
{
	return 0;
}

struct file_operations scullToy_fops = {			// 初始化file_operations結構
	.owner =	THIS_MODULE,						// 用來連結裝置的functions
	.open =		scullToy_open,
	.release =	scullToy_release,
	.read =		scullToy_read,
	.write =	scullToy_write,
};

/* ============================================================================
 * Module init and exit
 * ============================================================================*/
static int __init scullToy_init(void)
{
	int ret = 0;
	dev_t dev = 0;	

	printk(KERN_ALERT "==> SCULLToy: Init...\n");

/* Step 1: 配置裝置編號*/
	ret = alloc_chrdev_region(&dev,			//動態地配置可用的裝置編號
			scullToy_minor,					//裝置次編號的起始值
			scullToy_TotalNum,				//申請的裝置總數
			"scullToy");					//裝置名稱	

	if (ret<0)								//判斷是否配置成功
	{
		printk("--> SCULLToy: alloc_chrdev_region failed.\n");
		return ret;							//若失敗，則回傳錯誤代碼
	}
	/* 配置成功後，dev為一個包含主次編號的裝置編號
	 * 可使用 major = MAJOR(dev)來取得主編號，用minor = MINOR(dev)取得次編號
	 * 相反的可用dev = MKDEV(major,minor) 來取得裝置編號 */
	scullToy_major = MAJOR(dev);
/* step 2: 進行裝置的註冊*/
	cdev_init(&cdev_Toy, &scullToy_fops);	//初始化cdev，注意"&"
	cdev_Toy.owner = THIS_MODULE;			
	ret = cdev_add(&cdev_Toy, dev, scullToy_TotalNum);
	if(ret<0)
	{
		printk("--> SCULLToy: Wrong at adding cdev\n");
		return ret;
	}
	//至此，簡易的Char Device Driver註冊已完成
	printk("--> SCULLToy: Char Device has been registered successfully.\n");
	return 0;
}


static void __exit scullToy_exit(void)
{
    printk(KERN_ALERT "==> SCULLToy: Exit...\n");
	cdev_del(&cdev_Toy);
	unregister_chrdev_region(MKDEV(scullToy_major, 0),	//主編號起始值
			scullToy_TotalNum);							//裝置總數
	
}

module_init(scullToy_init);
module_exit(scullToy_exit);
MODULE_LICENSE("GPL");

