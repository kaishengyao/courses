function w12_lecture_1_fft
% winter 12 lecture on fft
clear all; close all; clc;

L = 20;
n = 128;

x2 = linspace(-L/2, L/2, n+1); x = x2(1:n);

u = exp(-x.^2);
ut =fft(u);
uts= fftshift(ut);

figure(1); plot(x, u);

figure(2); plot(abs(ut));
figure(3); plot(abs(uts));


end

