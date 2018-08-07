# James Milne's mex

## A simple macro-expander for Fortran 77

---

## Usage:

The command:

```
mex file.mf
```

Will produce the file: ```file.f```.

---

## Install:

You can use the provided Makefile:

```
make install
```

You can also tweak the install location by setting PREFIX, and BIN.

Uninstall is similar:

```
make uninstall
```

If you changed any value on install, make sure you also change it on uninstall.

*(mex is also self-contained. Copy it to anywhere in PATH if you would rather.)*

---

## Macro Language

The language is exceptionally simple, and without syntax checking.

If a line begins with '#', then it is converted to a comment.

e.g.

```
> # Hello, World!
c Hello, World!
```

If a line begins with a number, it is treated as a line number.

e.g.

```
> 100 print *, "This has a line number"
 100  print *,"This has a line number"
```

Otherwise, mex assumes we have a valid expression.

e.g.

```
> print *, "Hello, World!"
      print *, "Hello, World!"
```

See also, [comparators](#comparators)

### Macros

mex also supports user-defined macros, but only simple ones. Find and replace.

If a ```.mex``` file exists, then each line is treated as a space-seperated key-value pair.

The given source file is checked for each key, pre- and appended with an underscore, and then if found, the value is replaced.

e.g.

.mex:

```
x 27
```

somefile.mf:

```
real x
x=_x_
```

Turns into:

somefile.f:

```
real x
x=27
```

### Comparators

mex also supports symbols as comparators, replacing them rather naively. But basically:

| Symbol | Fortran Equivalent | Plain English         |
| ------ | ------------------ | --------------------- |
| >      | .gt.               | Greater Than          |
| <      | .lt.               | Less Than             |
| <=     | .le.               | Less Than or Equal    |
| >=     | .ge.               | Greater Than or Equal |
| ==     | .eq.               | Equal                 |
| !=     | .ne.               | Not Equal             |
| &&     | .and.              | And                   |
| \|\|     | .or.               | Or                    |
| !      | .not.              | Not                   |
| \|^     | .xor.              | Exclusive Or          |
| ~=     | .eqv.              | Equivalent            |
| ~!     | .neqv.             | Not Equivalent        |


---

## License

mex is released under Creative Commons 0 license, as close to Public Domain as I can.

The exact legal code can be found in the [LICENSE](LICENSE) file.
