# repo for competition os 2023 with kernel branch

```
ref --- ref of pre-works and xv6-riscv
mfos --- may be the main work dir, which means `minium full-featured os`
```
# KEY TASK
zym: memory layout, vm, mmu, pagetable
ljh: process scheduling, syscall
lh: filesystem

## code style
we use linux kernel code style, just use .clang-format from root dir

## doc
all doc should put in docs dir, each functionality should have a markdown spec.
you can put your personal note which competition-related in a markdown file named by your id to let people knows what we learned

## devlop
we will protect main branch and we devlop under own branch, note your commit format in your branch

## commit
### commit spec:
- make sure your commited work is completed
- make sure your commit subject is less than 50 characters long but enough to describe what you mainly do
- make sure you follow this format:

```
subject: [PART]:[TAG][One sentence description]

description: describe what this commit do in less than 60 characters each lines
```
  - [TAG]: description should start with a capital [TAG] and describe with an imperative sentance, which means you need make sure your describtion is started by [TAG]
    - Fixes: fix pre-issue
    - Add: add new functionality
    - Refactor: some code is being restructured without functional change
  - [PART]:  which part you modify

- here is an example
```
ext4: Add support for case-insensitive file names

This patch adds support for case-insensitive file names to the ext4 filesystem. This is useful for users who are migrating from a case-insensitive filesystem like NTFS or HFS+ to ext4, and want to preserve the case-insensitivity of their file names.

The new feature is implemented using a new mount option, "case_insensitive", which can be set at mount time or in /etc/fstab. When this option is enabled, file names in the ext4 filesystem will be treated as case-insensitive, so that files with the same name but different case will be treated as the same file.
```

(thats all for a great work flow

### set your template
```shell
git config commit.template .gitmessage
```

# TODO
- code test solutions
