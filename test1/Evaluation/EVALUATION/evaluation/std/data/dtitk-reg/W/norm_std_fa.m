
clear all;
clc;
%fa的归一化标准差

% dtitk_fa
[filename pathname]=uigetfile('*.nii');
dtitk_s1=load_nii(filename,[],1);
[filename pathname]=uigetfile('*.nii');
dtitk_s2=load_nii(filename,[],1);
[filename pathname]=uigetfile('*.nii');
dtitk_s3=load_nii(filename,[],1);
[filename pathname]=uigetfile('*.nii');
dtitk_s4=load_nii(filename,[],1);
[filename pathname]=uigetfile('*.nii');
dtitk_s5=load_nii(filename,[],1);
[filename pathname]=uigetfile('*.nii');
dtitk_s6=load_nii(filename,[],1);
[filename pathname]=uigetfile('*.nii');
dtitk_s7=load_nii(filename,[],1);
[filename pathname]=uigetfile('*.nii');
dtitk_s8=load_nii(filename,[],1);
[filename pathname]=uigetfile('*.nii');
dtitk_s9=load_nii(filename,[],1);
[filename pathname]=uigetfile('*.nii');
dtitk_s10=load_nii(filename,[],1);


for x=1:128
    for y=1:128
        for z=1:64
            FA_mean(x,y,z)=(dtitk_s1.img(x,y,z)+dtitk_s2.img(x,y,z)+dtitk_s3.img(x,y,z)+dtitk_s4.img(x,y,z)+dtitk_s5.img(x,y,z)+...
            dtitk_s6.img(x,y,z)+dtitk_s7.img(x,y,z)+dtitk_s8.img(x,y,z)+dtitk_s9.img(x,y,z)+dtitk_s10.img(x,y,z))/10;
        end
    end
end

W_std=sqrt(((dtitk_s1.img-FA_mean).^2+(dtitk_s2.img-FA_mean).^2+...
    (dtitk_s3.img-FA_mean).^2+(dtitk_s4.img-FA_mean).^2+(dtitk_s5.img-FA_mean).^2+...
    (dtitk_s6.img-FA_mean).^2+(dtitk_s7.img-FA_mean).^2+(dtitk_s8.img-FA_mean).^2+...
    +(dtitk_s9.img-FA_mean).^2+(dtitk_s10.img-FA_mean).^2)/9);


save W_std W_std;


 
 
 

