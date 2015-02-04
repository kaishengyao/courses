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
kx = 1:sx;
ky = 1:sy;
cx = round(sx/2 + 1); 
cy = round(sy/2 + 1);
Imgfs = fftshift(Imgf);
[Kx,Ky] = meshgrid(ky,kx); 
F = exp(-0.0001*(Kx - cx).^2 - 0.0001*(Ky - cy).^2);
Imgfsf = Imgfs .* F;
Imgr = ifft2(ifftshift(Imgfsf));
subplot(2,2,4); pcolor(abs(Imgr)), shading interp; 

