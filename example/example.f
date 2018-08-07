      program area
      real r, a, pi
c  Set pi to a constant
      parameter(pi=3.1416)
      print *,"What radius?"
c  Read from user... This can crash
      read *,r
      a=pi*r**2
c  Show the area of the circle!
      print *,"Area:",a
      end
