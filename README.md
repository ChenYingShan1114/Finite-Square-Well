c# Finite Square Well
In quantum mechanics, the energy eigenvalues of finite potential square well is given by transcendental equation. Therefore, it can be solved numerically, using a computer or graphically. In this file, one-variable Newton's method is used to find the roots of eigenenergys.

## System conditions
Consider an electron in a quantum square well potential of depth $V=-13.6 \ \mathrm{eV}$ and half-width $a=20a_0$ where $a_0$ is the Bohr radius.

## Energy Equations
The energy eigenvalues, $E>V$, are given by the transcendental equations. For the odd states, 
```math
\sqrt{-E} = \sqrt{E-V}\tan\left(\frac{a}{\hbar}\sqrt{2m(E-V)}\right)
```
, and the even states
```math
\sqrt{-E} = -\sqrt{E-V}\cot\left(\frac{a}{\hbar}\sqrt{2m(E-V)}\right)
```

## Newton's Method
The Newton's method is a way to solve for $x^\*$ such that $f(x^\*)=0$. It is based on Taylor expansion of a general function $f(x)$ around the root $x^\*$. Suppose that there is an initial guess near the root called $x_1$, and the error may be written as $\delta x=x_1-x^\*$. Then, the Taylor expansion of $f(x^\*)$ is
```math
f(x^*) = f(x_1 - \delta x) = f(x_1) - \delta x \frac{df(x_1)}{dx} + O(\delta x^2)
```
and it can also be written as 
```math
\delta x = \frac{f(x_1)}{f'(x_1)} + O(\delta x^2)
```
where $O(\delta x^2)$ term can be viewed as the truncation error. $\delta x$ can be used to **correct** the initial guess
```math
x_2 = x_1 - \delta x = x_1 - \frac{f(x_1)}{f'(x_1)}
```
Therefore, this procedure may be iterated as 
```math
x_{n+1} = x_n - \frac{f(x_n)}{f'(x_n)}
```
to improve our guess further until the desired accuracy is obtained.
Otherwise, the equation can modified as
```math
x_{n+1} = x_n - r\frac{f(x_n)}{f'(x_n)}
```
where $0 < r < 1$ to decrease the distance between $x_{n+1}$ and $x_{n}$ and find the root closest to out initial guess.

## Initial Guess
The eigenenergys of an infinite square well with the same width is
```math
E_n = \frac{n^2\pi^2 \hbar^2}{8ma^2} - 13.6
```
Use the value of each $n$ as the initial guess of the finite square well.
