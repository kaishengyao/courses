clear all; close all; clc;

Img = imread('c:\Users\kaisheny\Pictures\withclassmatesontopofyujiashan.jpg', 'JPEG');

Imbw = rgb2gray(Img); 
Imgdbw = double(Imbw);
% add noise
N = 1.*randn(size(Imgdbw));
Imgdbwn = Imgdbw + N*10;
subplot(2,2,1);imshow(uint8(Imgdbw));
subplot(2,2,2);imshow(uint8(Imgdbwn));

% filtering with Gaussian filter in frequency domain
Imgf = fft2(Imgdbwn);
subplot(2,2,3); pcolor(log(abs(fftshift(Imgf)))), shading interp;

[sx,sy] = size(Imgf);
x = linspace(0,1,sx);
y = linspace(0,1,sy);
dx = x(2) - x(1);
dy = y(2) - y(1);

onex = ones(sx,1);
oney = ones(sy,1);
Dx = spdiags([onex -2 * onex onex], [-1 0 1], sx, sx)./dx^2;
Ix = eye(sx);
Dy = spdiags([oney -2 * oney oney], [-1 0 1], sy, sy)./dy^2;
Iy = eye(sy);

L = kron(Iy, Dx) + kron(Dy, Ix);

tspan = [0 0.002 0.004 0.006];
D = 0.0005;

u0 = reshape(Imgdbwn, sx * sy, 1);
[t, usol] = ode113('imag_rhs', tspan, u0, [], L, D);

for j = 1:length(t)
    Imgclean = uint8(reshape(usol(j,:), sx, sy));
    subplot(2,2,j), imshow(Imgclean);
end

% denoising only part of image
u0 = reshape(Imgdbwn, sx * sy, 1);
Dregion = zeros(size(u0));
Dregion(80:1:8000) = 0.005;
[t, usolregion] = ode113('imag_region_rhs', tspan, u0, [], L, Dregion);

figure(2);
for j = 1:length(t)
    Imgclean = uint8(reshape(usolregion(j,:), sx, sy));
    subplot(2,2,j), imshow(Imgclean);
end

