# mex

## A simple macro-expander for Fortran 77

---

## Usage:

The command:

```
mex file.mf
```

Will produce the file: ```file.f```.

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

**Caution**: These macros pass through sed. Escape characters that may behave strangely, such as ```.```. (This should be fixed in future.)

---

## License

mex is released under Creative Commons 0 license, as close to Public Domain as I can.

The exact legal code can be found in the [LICENSE](LICENSE) file.
