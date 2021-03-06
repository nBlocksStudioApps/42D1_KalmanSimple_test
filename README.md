[![](https://img.shields.io/badge/nBlocksStudioNodes-blue.svg)](https://github.com/nBlocksStudioNodes)

# [42D1_KalmanSimple_test](https://github.com/nBlocksStudioApps/42D1_KalmanSimple_test)

An experimental repository for 42D:

> A schematic Design for Testing the Node [KalmanSimple](https://github.com/nBlocksStudioNodes/nblocks_kalmansimple) and [42D_KalmanSimple_test_SCH](https://github.com/nBlocksStudioApps/42D_KalmanSimple_test_SCH)

With scope to import an existing [nBlocksStudio](https://github.com/nblocksStudio/nblocksStudio.github.io) project to the new (December 2021) [Keil Studio Cloud](https://www.keil.arm.com/), which replaces both [mbed-online-compiler](https://os.mbed.com/handbook/mbed-Compiler) and [mbed-studio](https://os.mbed.com/studio/) IDE

## The problem
[nBlocksStudio](https://github.com/nblocksStudio/nblocksStudio.github.io) repositories contain git controlled sub-directories for the libraries. The project tree is created automatically from the [nBlocksStudio](https://github.com/nblocksStudio/nblocksStudio.github.io) translator.

[nBlocksStudio](https://github.com/nblocksStudio/nblocksStudio.github.io) translator does not create/manage [git submodules](https://git-scm.com/book/en/v2/Git-Tools-Submodules), so when the local repo is pushed to a remote git repo, the remote libraries sub-directories are empty. 
> to review:
 Manually managing multiple [git submodules](https://git-scm.com/book/en/v2/Git-Tools-Submodules) takes time and is error-prone 

As result when the repo is cloned from github, the library sub-directories have no content. 

> to review: For importing to [Keil Studio](https://www.keil.arm.com/), even if the submoules were properly managed, the library subfolders can't be imported!!!


## A tested solution

Note the existence of `.git` sub-directory. 
This is what we want to remove from all sub-directories under `nlib` sub-directory

<p align="center">
<img
src="img/03.PNG"
width = 900
/>
</p>

We first copy the [nBlocksStudio](https://github.com/nblocksStudio/nblocksStudio.github.io) repo locally to a new one, omitting the huge `mbed-os` sub-directory.  
Then we add the `removeGit.cmd` DOS batch-file to the project-repo-root and we run it.
<p align="center">
<img
src="img/01.PNG"
width = 800
/>
</p>

The .git subdirectories are removed from **all**  sub-directories

<p align="center">
<img
src="img/02.PNG"
width = 900
/>
</p>

The `removeGit.cmd` DOS batch file content is:  
`FOR /d /r . %%d IN (".git") DO @IF EXIST "%%d" rd /s /q "%%d"`

<p align="center">
<img
src="img/04.PNG"
width = 800
/>
</p>

----

### Importing to Keil-studio
* Create a new  [Keil Studio](https://www.keil.arm.com/) project:
  * Use the blinky project example 
  * mbed-os5
  * bare metal
* Remove `main.c` and `readme.md` files, from the newly created project
* **Drag...**  from the local repo 
  * nlib
  * README.md 
  * main.cpp
<p align="center">
<img
src="img/06.PNG"
width = 400
/>
</p>

* **...& Drop**  to the created Keil-Studio project
<p align="center">
<img
src="img/05.PNG"
width = 400
/>
</p>

* Compile and Update `#indlude` path errors, since `mbed-studio` needs the full path for the `#indlude` files, and [Keil Studio](https://www.keil.arm.com/) needs only the library files without the path.

<p align="center">
<img
src="img/08.PNG"
width = 900
/>
</p>


Below: updated `#indlude` without the path
<p align="center">
<img
src="img/09.PNG"
width = 900
/>
</p>

* Finally: compile without errors and ...

<p align="center">
<img
src="img/07.PNG"
width = 900
/>
</p>

* Download the compiled binary, to flash the target Microcontroller.
<p align="center">
<img
src="img/10.PNG"
width = 900
/>
</p>