#include <stdio.h>
#include <sys/types.h>

int main(){
  // 3 times cycle
  // for(int i = 0; i < 3; i++){
  //   fork();
  //   sleep(5);
  // }
  // output of pstree
  // ├─gnome-terminal-─┬─bash───ex2─┬─ex2─┬─ex2───ex2
  // │                 │            │     └─ex2
  // │                 │            ├─ex2───ex2
  // │                 │            └─ex2

  // 8 procces are created, 2^n where n is number of iterations
  // during the cycle child processes are created
  // one fork() which created this process is not copied
  // while other are run by the children
  // so there is 8 processes


  // 5 times cycle

  for(int i = 0; i < 5; i++){
     fork();
     sleep(5);
  }

  // output after pstree
  // 32 processes are created, 2^n processes are created
  // where n is number of interation

  // ├─gnome-terminal-─┬─bash───ex2─┬─ex2─┬─ex2─┬─ex2─┬─ex2───ex2
  // │                 │            │     │     │     └─ex2
  // │                 │            │     │     ├─ex2───ex2
  // │                 │            │     │     └─ex2
  // │                 │            │     ├─ex2─┬─ex2───ex2
  // │                 │            │     │     └─ex2
  // │                 │            │     ├─ex2───ex2
  // │                 │            │     └─ex2
  // │                 │            ├─ex2─┬─ex2─┬─ex2───ex2
  // │                 │            │     │     └─ex2
  // │                 │            │     ├─ex2───ex2
  // │                 │            │     └─ex2
  // │                 │            ├─ex2─┬─ex2───ex2
  // │                 │            │     └─ex2
  // │                 │            ├─ex2───ex2
  // │                 │            └─ex2



  // during the cycle child processes are created
  // one fork() which create this process is not copied
  // while other are run by the children
  // so there is 16 processes because fork was run more

  return 0;
}
