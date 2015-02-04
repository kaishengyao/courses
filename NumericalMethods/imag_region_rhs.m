function rhs = imag_region_rhs(tspan, u, dummy, L,D)
rhs = D .* (L * u);
