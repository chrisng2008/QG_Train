[toc]

# Git

语法与linux相类似

pwd显示当前目录

进入目标文件夹 `git init`使本目录变成Git肯伊管理的仓库

**注意**：编辑文件不要用微软记事本，可以用其他编辑器，改用UTF-8编码。

```shell
git add readme.txt	#将文件添加至仓库
git commit -m "wrote a readme file"
#-m后面输入的是本次提交的说明，可以输入任意内容，当然最好是有意义的，这样你就能从历史记录里方便地找到改动记录
```


## 时光穿梭机

### 版本回退

```shell
git log#查看日志，命令显示从最近到最远的提交日志
git log --pretty=oneline#如果嫌输出信息太多，看得眼花缭乱，可以加上后缀
####################
git reset --hard HEAD^#回退到上一版本
#如果需要回退到最新版本，可以上翻之前的log
git reset --hard 1094a
#1094a是上一版本号的随意前几位
git reflog #记录了每一次的版本号
```



### 工作区和缓存区概念

**工作区**的文件 经过`git add`添加到**暂存区**stage,`git commit`将stage中文件添加到master



```shell
cat readme.txt
#将文件内容打印显示
```

**注意**：修改文件后需要将使用`git add`再使用`git commit`。总而言之，现在，你又理解了Git是如何跟踪修改的，每次修改，如果不用`git add`到暂存区，那就不会加入到`commit`中。

### 撤销操作

```shell
git checkout -- file
```

总结：`git checkout --file`命令总是撤销到上一步，如果是没有`git add`则将撤销文件的修改状态，如果已经`git commit`,则撤销到`git add` 的状态

**注意**：`--`很重要，如果没有`--`，就变成了“切换到另一个分支”的命令，我们在后面的分支管理中会再次遇到`git checkout`命令。

### 删除操作

```shell
#一般情况，直接用rm删除文件
rm filename

#case one
#要从版本库中删除该文件
git rm test.txt
rm 'test.txt'
#case two
#误删恢复
git checkout -- test.txt
```

## 远程仓库

GIthub

1. 创建SSH Key。在用户主目录下，看看有没有.ssh目录，如果有，再看看这个目录下有没有`id_rsa`和`id_rsa.pub`这两个文件，如果已经有了，可直接跳到下一步。如果没有，打开Shell（Windows下打开Git Bash），创建SSH Key：

   ```shell
   ssh-keygen -t rsa -C "youremail@example.com"
   ```


```shell
git clone https://github.com/chrisng2008/QG_Train.git#远程仓库地址
```

```shell
git remote add origin https://github.com/chrisng2008/QG_Train.git
```

```shell
 git push origin master
```

### 创建与合并分支

#### 创建分支

```shell
git checkout -b dev#创建分支dev
```

```shell
#其中上述加上参数-b则代表以下命令
git branch dev
git checkout dev#切换分支
```

```shell
git branch#查看当前分支
```

#### 合并分支

```shell
git merge dev#合并分支
```

```shell
git branch -d dev#合并后删除分支
```

**WARNING**：注意到上述``git checkout dev``撤销操作``git checkout --<file>``很像，容易混淆，所以我们使用`switch`更加科学

```shell
git switch -c dev#创建并切换到新的分支
git switch main#切换到原有的分支
```

---

**git**鼓励使用大量分支

查看分支：`git branch`

创建分支：`git branch <name>`

切换分支：`git checkout <name>`或者`git switch <name>`

创建+切换分支：`git checkout -b <name>`或者`git switch -c <name>`

合并某分支到当前分支：`git merge <name>`

删除分支：`git branch -d <name>`

---

### 解决冲突

什么是冲突？

```shell
git switch -c feature1#创建并切换分支
#然后修规README.md
#在最后加Creating a new branch is quick AND simple.
git add readme.txt#在featurel上提交
git switch master
#在分支master上修改
#最后改为Creating a new branch is quick AND simple.
git add README.md
git merge feature1#这种情况下就不能出现快速合并
```

这样的话就会出现冲突

解决冲突的方法就是手动修改成我们需要的内容在提交

```shell
git add README.md
git commit -m "conflict fixed"
git branch -d feature1#最后删除分支
```

用`git log --graph`命令可以看到分支合并图。