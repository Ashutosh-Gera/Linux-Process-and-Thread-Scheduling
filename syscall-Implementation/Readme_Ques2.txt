Readme For ques2(according to given pdf)

We need to write a system call, kernel 2d memcpy(), which copies one 2-D floating
point matrix to another. You would require using kernel functions like
copy from user() and copy from user() to read data bytes from user space
and write back to user space. In other words, this is a version of memcpy() that
relies on the kernel to do the necessary copy operations, which are otherwise
usually done directly in the user space (using the standard C library routines).


We first create a git repository in the linux-5.19.9 folder which is inside the build folder
in kern. after this we add "syscall_64.tbl" file to the repository and then added sys.c file.
After this we commit the changes to the repository. 

Now to add the system call we first write SYSCALL_DEFINE4 with parameters source matrix,
destination matrix, row, column.

We add this system call into the table which lists the system calls we open the "syscall_64.tbl"
using the vim text editor. We add it after the call 447 and then save and exit the editor.
Now to add definition we navigate to the syscall directory which contains all the definitions
We create a function in which we use __copy_from_user() command to copy the content in mat1
(source matrix) and then use __copy_to_user() command to write the copied content from mat1 to
mat 2(destination matrix). If any error is generated while copying then syscall will return
-1 else if the process carries out successfully then it returns 0. 

After adding the syscall, we need to write the git diff to diff.txt file to check the differences
we made while adding the syscall. We do so by first creating a diff.txt file in linux-5.19.9
folder and then in terminal run the following command "git diff >> diff.txt".

We also created a tester file to check the working of the syscall, where we create a matrix
which has i,j element as i+j, which we copy to other empty matrix using the syscall.

Lastly we use git diff >> diff. patch to create a patch file which contains the differences 
we made while adding the syscall.

Thank you
Ashutosh Gera
2021026
CSE
