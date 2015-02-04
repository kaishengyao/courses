function rhs = imag_rhs(tspan, u, dummy, L,D)
rhs = D * L * u;
