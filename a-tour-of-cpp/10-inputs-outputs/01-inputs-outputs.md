Chapter 10 is an interesting one that gives us an overview about **I/O operations** in:
- *input* from keyboard;
- *output* to screen;
- I/O on files.

Moreover, it presents the useful APIs to deal with **File System** and **Pathnames**.

Using `<filesystem>`, we can portably:
- express **file system paths** and navigate through a file system;
- examine **file types** and the permissions associated with them

A `path` is quite a complicated class, capable of handling the native character sets and *conventions* of
*many operating systems*.

A `path` is **not checked** for validity *until it is used*. Even then, its validity depends on the conventions of
the system on which the program runs.

They can be used to:
- open a file;
- check if a file/directory exists;
- manipulate (create and remove) files and directories;
- build new pathnames;
- etc

There ary many available functions to use `path`. Take a look at Chapter 10 for more information.

**PS:** using `path` can be a little difficult, because some OS (actually their C++ compilers), like MacOS,
cannot provide support for it.