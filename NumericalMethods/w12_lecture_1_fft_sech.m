function w12_lecture_1_fft_sech
% winter 12 lecture on fft
clear all; close all; clc;

L = 20;
n = 128;

x2 = linspace(-L/2, L/2, n+1); x = x2(1:n);
k  = (2*pi/L) * [0:(n/2-1) (-n/2):-1] ;
u = sech(x);
ud = -u .* tanh(x);
ud2 = u - 2 * u.^3;

ut =fft(u);
uts= fftshift(ut);
udt = (i*k).* ut;
ud2t = (i*k).^2 .* ut;

figure(1); plot(x, ud, 'r', x, ifft(udt), '-ok');
figure(2); plot(x, ud2, 'r', x, ifft(ud2t), '-ok');


end