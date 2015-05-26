#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/kernel.h>

int first = 0, second = 0;
char operation = '+';

ssize_t calc_first_write(struct file *filp, const char *buf, size_t count, loff_t *offp)
{
	int i = 0, tmp = 0, sign = 1;
	
	if (buf[0] == '-')
		sign = -1;
	else if (buf[0] < '0' || buf[0] > '9') {
		printk(KERN_INFO "Invalid parameter.\n");
		return count;
	} else {
		tmp = tmp * 10 + (buf[0]-'0');	
	}

	for (i = 1; i < count - 1; ++i) {
		if (buf[i] < '0' || buf[i] > '9') {
			printk(KERN_INFO "Invalid parameter.\n");
			return count;
		} else {
			tmp = tmp * 10 + (buf[i]-'0');
		}
	}

	first = tmp * sign;
	return count;
}

ssize_t calc_second_write(struct file *filp, const char *buf, size_t count, loff_t *offp)
{
	int i = 0, tmp = 0, sign = 1;
	
	if (buf[0] == '-')
		sign = -1;
	else if (buf[0] < '0' || buf[0] > '9') {
		printk(KERN_INFO "Invalid parameter.\n");
		return count;
	} else {
		tmp = tmp * 10 + (buf[0]-'0');	
	}

	for (i = 1; i < count - 1; ++i) {
		if (buf[i] < '0' || buf[i] > '9') {
			printk(KERN_INFO "Invalid parameter.\n");
			return count;
		} else {
			tmp = tmp * 10 + (buf[i]-'0');
		}
	}

	second = tmp * sign;
	return count;
}

MODULE_LICENSE("GPL");
module_init(calc_proc_init);
module_exit(calc_proc_exit);

