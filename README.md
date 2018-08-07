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

---

## License

mex is released under Creative Commons 0 license, as close to Public Domain as I can.

The exact legal code can be found in the [LICENSE](LICENSE) file.
