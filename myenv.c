/*
 *  myenv.c : env コマンドのクローン
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#ifdef __linux__
#include "myputenv.h"
#endif
extern char **environ;
int main(int argc,char *argv[]) { 
  int i = 1;
  while (putenv(argv[i]) == 0) {
    putenv(argv[i]);
    i++;
  }
  if (i == argc) {
    for (int i=0; environ[i]!=NULL; i++) { // NULLが見つかるまで
      printf("%s\n", environ[i]); // 環境変数を印刷
    }
    return 0;
  }
  execvp(argv[i], &argv[i]);
  perror(argv[i]);
}

/* 実行例

ここに実行例を書く

% make
cc -D_GNU_SOURCE -Wall -std=c99 -o myenv myenv.c myputenv.c

% ./myenv LC_TIME=ja_JP.UTF-8 TZ=Cuba ls -l 
total 392
-rw-r--r--  1 hoshinoatumi  staff     132  6月 29 22:20 Makefile
-rw-r--r--  1 hoshinoatumi  staff    1268  6月 29 22:20 README.md
-rw-r--r--  1 hoshinoatumi  staff  139098  6月 29 22:20 README.pdf
-rwxr-xr-x  1 hoshinoatumi  staff   33736  6月 30 21:56 myenv
-rw-r--r--  1 hoshinoatumi  staff    4349  6月 30 21:56 myenv.c
-rwxr-xr-x  1 hoshinoatumi  staff     216  6月 29 22:20 myputenv.c
-rw-r--r--  1 hoshinoatumi  staff      93  6月 29 22:20 myputenv.h

% ./myenv                               
OSLogRateLimit=64
MallocNanoZone=0
USER=hoshinoatumi
SECURITYSESSIONID=186b6
COMMAND_MODE=unix2003
__CFBundleIdentifier=com.microsoft.VSCode
PATH=/Users/hoshinoatumi/.antigravity/antigravity/bin:/Users/hoshinoatumi/
Library/Application Support/Code/User/globalStorage/github.copilot-chat/
debugCommand:/Users/hoshinoatumi/Library/Application Support/Code/User/
globalStorage/github.copilot-chat/copilotCli:/opt/homebrew/bin:/opt/homebrew/
sbin:/Library/Frameworks/Python.framework/Versions/3.13/bin:/Library/
Frameworks/Python.framework/Versions/3.10/bin:/usr/local/bin:/System/
Cryptexes/App/usr/bin:/usr/bin:/bin:/usr/sbin:/sbin:/var/run/
com.apple.security.cryptexd/codex.system/bootstrap/usr/local/bin:/var/run/
com.apple.security.cryptexd/codex.system/bootstrap/usr/bin:/var/run/
com.apple.security.cryptexd/codex.system/bootstrap/usr/appleinternal/bin:/
opt/pmk/env/global/bin:/opt/X11/bin:/Library/Apple/usr/bin:/Applications/
VMware Fusion.app/Contents/Public:/usr/local/share/dotnet:~/.dotnet/tools:/
Library/Frameworks/Mono.framework/Versions/Current/Commands:/Users/
hoshinoatumi/Library/Application Support/Code/User/globalStorage/
github.copilot-chat/debugCommand:/Users/hoshinoatumi/Library/
Application Support/Code/User/globalStorage/github.copilot-chat/copilotCli:/
Users/hoshinoatumi/.antigravity/antigravity/bin
SHELL=/bin/zsh
LaunchInstanceID=034AF55C-93FF-4553-A116-19C11522696B
__CF_USER_TEXT_ENCODING=0x1F5:0x1:0xE
XPC_SERVICE_NAME=0
DISPLAY=/private/tmp/com.apple.launchd.5wxH8GFikL/org.xquartz:0
SSH_AUTH_SOCK=/private/tmp/com.apple.launchd.b9XlYdar5u/Listeners
XPC_FLAGS=0x0
LOGNAME=hoshinoatumi
TMPDIR=/var/folders/pc/q9rh_f9x5p52_3w4ttgqywn00000gn/T/
SHLVL=1
PWD=/Users/hoshinoatumi/Syspro/kadai09-i23hosino
OLDPWD=/Users/hoshinoatumi/Syspro/kadai09-i23hosino
LANG=C.UTF-8
HOMEBREW_PREFIX=/opt/homebrew
HOMEBREW_CELLAR=/opt/homebrew/Cellar
HOMEBREW_REPOSITORY=/opt/homebrew
FPATH=/opt/homebrew/share/zsh/site-functions:/opt/homebrew/share/zsh/
site-functions:/usr/local/share/zsh/site-functions:/usr/share/
zsh/site-functions:/usr/share/zsh/5.9/functions
INFOPATH=/opt/homebrew/share/info:/opt/homebrew/share/info:
JAVA_HOME=/Library/Java/JavaVirtualMachines/liberica-jdk-21-full.jdk/Contents/
Home
TERM_PROGRAM=vscode
TERM_PROGRAM_VERSION=1.125.0
COLORTERM=truecolor
GIT_ASKPASS=/Applications/Visual Studio Code.app/Contents/Resources/app
/extensions/git/dist/askpass.sh
VSCODE_GIT_ASKPASS_NODE=/Applications/Visual Studio Code.app/Contents/
Frameworks/Code Helper (Plugin).app/Contents/MacOS/Code Helper (Plugin)
VSCODE_GIT_ASKPASS_EXTRA_ARGS=
VSCODE_GIT_ASKPASS_MAIN=/Applications/Visual Studio Code.app/Contents/
Resources/app/extensions/git/dist/askpass-main.js
VSCODE_GIT_IPC_HANDLE=/var/folders/pc/q9rh_f9x5p52_3w4ttgqywn00000gn/T/
vscode-git-ab15eb5008.sock
COPILOT_DEBUG_NONCE=ef24488e1a104a101d2db2e15e37f9a6
VSCODE_INJECTION=1
ZDOTDIR=/Users/hoshinoatumi
USER_ZDOTDIR=/Users/hoshinoatumi
TERM=xterm-256color
VSCODE_PROFILE_INITIALIZED=1
VSCODE_PYTHON_AUTOACTIVATE_GUARD=1
_=/Users/hoshinoatumi/Syspro/kadai09-i23hosino/./myenv

% ./myenv LC_TIME=ja_JP.UTF-8               
OSLogRateLimit=64
MallocNanoZone=0
USER=hoshinoatumi
SECURITYSESSIONID=186b6
COMMAND_MODE=unix2003
__CFBundleIdentifier=com.microsoft.VSCode
PATH=/Users/hoshinoatumi/.antigravity/antigravity/bin:/Users/hoshinoatumi/
Library/Application Support/Code/User/globalStorage/github.copilot-chat/
debugCommand:/Users/hoshinoatumi/Library/Application Support/Code/User/
globalStorage/github.copilot-chat/copilotCli:/opt/homebrew/bin:/opt/homebrew/
sbin:/Library/Frameworks/Python.framework/Versions/3.13/bin:/Library/
Frameworks/Python.framework/Versions/3.10/bin:/usr/local/bin:/System/
Cryptexes/App/usr/bin:/usr/bin:/bin:/usr/sbin:/sbin:/var/run/
com.apple.security.cryptexd/codex.system/bootstrap/usr/local/bin:/var/run/
com.apple.security.cryptexd/codex.system/bootstrap/usr/bin:/var/run/
com.apple.security.cryptexd/codex.system/bootstrap/usr/appleinternal/bin:/
opt/pmk/env/global/bin:/opt/X11/bin:/Library/Apple/usr/bin:/Applications/
VMware Fusion.app/Contents/Public:/usr/local/share/dotnet:~/.dotnet/tools:/
Library/Frameworks/Mono.framework/Versions/Current/Commands:/Users/
hoshinoatumi/Library/Application Support/Code/User/globalStorage/
github.copilot-chat/debugCommand:/Users/hoshinoatumi/Library/
Application Support/Code/User/globalStorage/github.copilot-chat/copilotCli:/
Users/hoshinoatumi/.antigravity/antigravity/bin
HOME=/Users/hoshinoatumi
SHELL=/bin/zsh
LaunchInstanceID=034AF55C-93FF-4553-A116-19C11522696B
__CF_USER_TEXT_ENCODING=0x1F5:0x1:0xE
XPC_SERVICE_NAME=0
DISPLAY=/private/tmp/com.apple.launchd.5wxH8GFikL/org.xquartz:0
SSH_AUTH_SOCK=/private/tmp/com.apple.launchd.b9XlYdar5u/Listeners
XPC_FLAGS=0x0
LOGNAME=hoshinoatumi
TMPDIR=/var/folders/pc/q9rh_f9x5p52_3w4ttgqywn00000gn/T/
SHLVL=1
PWD=/Users/hoshinoatumi/Syspro/kadai09-i23hosino
OLDPWD=/Users/hoshinoatumi/Syspro/kadai09-i23hosino
LANG=C.UTF-8
HOMEBREW_PREFIX=/opt/homebrew
HOMEBREW_CELLAR=/opt/homebrew/Cellar
HOMEBREW_REPOSITORY=/opt/homebrew
FPATH=/opt/homebrew/share/zsh/site-functions:/opt/homebrew/share/zsh/
site-functions:/usr/local/share/zsh/site-functions:/usr/share/zsh/
site-functions:/usr/share/zsh/5.9/functions
INFOPATH=/opt/homebrew/share/info:/opt/homebrew/share/info:
JAVA_HOME=/Library/Java/JavaVirtualMachines/liberica-jdk-21-full.jdk/
Contents/Home
TERM_PROGRAM=vscode
TERM_PROGRAM_VERSION=1.125.0
COLORTERM=truecolor
GIT_ASKPASS=/Applications/Visual Studio Code.app/Contents/Resources/
app/extensions/git/dist/askpass.sh
VSCODE_GIT_ASKPASS_NODE=/Applications/Visual Studio Code.app/Contents/
Frameworks/Code Helper (Plugin).app/Contents/MacOS/Code Helper (Plugin)
VSCODE_GIT_ASKPASS_EXTRA_ARGS=
VSCODE_GIT_ASKPASS_MAIN=/Applications/Visual Studio Code.app/Contents/
Resources/app/extensions/git/dist/askpass-main.js
VSCODE_GIT_IPC_HANDLE=/var/folders/pc/q9rh_f9x5p52_3w4ttgqywn00000gn/T/
vscode-git-ab15eb5008.sock
COPILOT_DEBUG_NONCE=ef24488e1a104a101d2db2e15e37f9a6
VSCODE_INJECTION=1
ZDOTDIR=/Users/hoshinoatumi
USER_ZDOTDIR=/Users/hoshinoatumi
TERM=xterm-256color
VSCODE_PROFILE_INITIALIZED=1
VSCODE_PYTHON_AUTOACTIVATE_GUARD=1
_=/Users/hoshinoatumi/Syspro/kadai09-i23hosino/./myenv
LC_TIME=ja_JP.UTF-8

% ./myenv A=B
OSLogRateLimit=64
MallocNanoZone=0
USER=hoshinoatumi
SECURITYSESSIONID=186b6
COMMAND_MODE=unix2003
__CFBundleIdentifier=com.microsoft.VSCode
PATH=/Users/hoshinoatumi/.antigravity/antigravity/bin:/Users/hoshinoatumi/
Library/Application Support/Code/User/globalStorage/github.copilot-chat/
debugCommand:/Users/hoshinoatumi/Library/Application Support/Code/User/
globalStorage/github.copilot-chat/copilotCli:/opt/homebrew/bin:/opt/homebrew/
sbin:/Library/Frameworks/Python.framework/Versions/3.13/bin:/Library/
Frameworks/Python.framework/Versions/3.10/bin:/usr/local/bin:/System/
Cryptexes/App/usr/bin:/usr/bin:/bin:/usr/sbin:/sbin:/var/run/
com.apple.security.cryptexd/codex.system/bootstrap/usr/local/bin:/var/run/
com.apple.security.cryptexd/codex.system/bootstrap/usr/bin:/var/run/
com.apple.security.cryptexd/codex.system/bootstrap/usr/appleinternal/bin:/
opt/pmk/env/global/bin:/opt/X11/bin:/Library/Apple/usr/bin:/Applications/
VMware Fusion.app/Contents/Public:/usr/local/share/dotnet:~/.dotnet/tools:/
Library/Frameworks/Mono.framework/Versions/Current/Commands:/Users/
hoshinoatumi/Library/Application Support/Code/User/globalStorage/
github.copilot-chat/debugCommand:/Users/hoshinoatumi/Library/
Application Support/Code/User/globalStorage/github.copilot-chat/copilotCli:/
Users/hoshinoatumi/.antigravity/antigravity/bin
HOME=/Users/hoshinoatumi
SHELL=/bin/zsh
LaunchInstanceID=034AF55C-93FF-4553-A116-19C11522696B
__CF_USER_TEXT_ENCODING=0x1F5:0x1:0xE
XPC_SERVICE_NAME=0
DISPLAY=/private/tmp/com.apple.launchd.5wxH8GFikL/org.xquartz:0
SSH_AUTH_SOCK=/private/tmp/com.apple.launchd.b9XlYdar5u/Listeners
XPC_FLAGS=0x0
LOGNAME=hoshinoatumi
TMPDIR=/var/folders/pc/q9rh_f9x5p52_3w4ttgqywn00000gn/T/
SHLVL=1
PWD=/Users/hoshinoatumi/Syspro/kadai09-i23hosino
OLDPWD=/Users/hoshinoatumi/Syspro/kadai09-i23hosino
LANG=C.UTF-8
HOMEBREW_PREFIX=/opt/homebrew
HOMEBREW_CELLAR=/opt/homebrew/Cellar
HOMEBREW_REPOSITORY=/opt/homebrew
FPATH=/opt/homebrew/share/zsh/site-functions:/opt/homebrew/share/zsh/
site-functions:/usr/local/share/zsh/site-functions:/usr/share/zsh/
site-functions:/usr/share/zsh/5.9/functions
INFOPATH=/opt/homebrew/share/info:/opt/homebrew/share/info:
JAVA_HOME=/Library/Java/JavaVirtualMachines/liberica-jdk-21-full.jdk/Contents/
Home
TERM_PROGRAM=vscode
TERM_PROGRAM_VERSION=1.125.0
COLORTERM=truecolor
GIT_ASKPASS=/Applications/Visual Studio Code.app/Contents/Resources/app/
extensions/git/dist/askpass.sh
VSCODE_GIT_ASKPASS_NODE=/Applications/Visual Studio Code.app/Contents/
Frameworks/Code Helper (Plugin).app/Contents/MacOS/Code Helper (Plugin)
VSCODE_GIT_ASKPASS_EXTRA_ARGS=
VSCODE_GIT_ASKPASS_MAIN=/Applications/Visual Studio Code.app/Contents/
Resources/app/extensions/git/dist/askpass-main.js
VSCODE_GIT_IPC_HANDLE=/var/folders/pc/q9rh_f9x5p52_3w4ttgqywn00000gn/T/
vscode-git-ab15eb5008.sock
COPILOT_DEBUG_NONCE=ef24488e1a104a101d2db2e15e37f9a6
VSCODE_INJECTION=1
ZDOTDIR=/Users/hoshinoatumi
USER_ZDOTDIR=/Users/hoshinoatumi
TERM=xterm-256color
VSCODE_PROFILE_INITIALIZED=1
VSCODE_PYTHON_AUTOACTIVATE_GUARD=1
_=/Users/hoshinoatumi/Syspro/kadai09-i23hosino/./myenv
A=B
*/
