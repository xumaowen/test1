
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
            
           FA_M=[dtitk_s1.img(x,y,z) dtitk_s2.img(x,y,z) dtitk_s3.img(x,y,z) dtitk_s4.img(x,y,z) dtitk_s5.img(x,y,z)...
            dtitk_s6.img(x,y,z) dtitk_s7.img(x,y,z) dtitk_s8.img(x,y,z) dtitk_s9.img(x,y,z) dtitk_s10.img(x,y,z)];
            
            
            FA_median(x,y,z)=median(FA_M);
        end
    end
end
%----------------------FA的中值图像-------------------------

atlas_std1=sqrt((dtitk_s1.img-FA_median).^2);
atlas_std2=sqrt((dtitk_s2.img-FA_median).^2);
atlas_std3=sqrt((dtitk_s3.img-FA_median).^2);
atlas_std4=sqrt((dtitk_s4.img-FA_median).^2);
atlas_std5=sqrt((dtitk_s5.img-FA_median).^2);
atlas_std6=sqrt((dtitk_s6.img-FA_median).^2);
atlas_std7=sqrt((dtitk_s7.img-FA_median).^2);
atlas_std8=sqrt((dtitk_s8.img-FA_median).^2);
atlas_std9=sqrt((dtitk_s9.img-FA_median).^2);
atlas_std10=sqrt((dtitk_s10.img-FA_median).^2);

%save atlas_std1 atlas_std1;
%save atlas_std2 atlas_std2;
%save atlas_std3 atlas_std3;
%save atlas_std4 atlas_std4;
%save atlas_std5 atlas_std5;
%save atlas_std6 atlas_std6;
%save atlas_std7 atlas_std7;
%save atlas_std8 atlas_std8;
%save atlas_std9 atlas_std9;
%save atlas_std10 atlas_std10;


d1=mean(mean(mean(atlas_std1)));
d2=mean(mean(mean(atlas_std2)));
d3=mean(mean(mean(atlas_std3)));
d4=mean(mean(mean(atlas_std4)));
d5=mean(mean(mean(atlas_std5)));
d6=mean(mean(mean(atlas_std6)));
d7=mean(mean(mean(atlas_std7)));
d8=mean(mean(mean(atlas_std8)));
d9=mean(mean(mean(atlas_std9)));
d10=mean(mean(mean(atlas_std10)));

%-------------------d为FA与中值的差值-------------------------------------

X=[d1 d2 d3 d4 d5 d6 d7 d8 d9 d10];

w1=(1-d1/max(X))^6; 
w2=(1-d2/max(X))^6;
w3=(1-d3/max(X))^6;
w4=(1-d4/max(X))^6; 
w5=(1-d5/max(X))^6; 
w6=(1-d6/max(X))^6;
w7=(1-d7/max(X))^6;
w8=(1-d8/max(X))^6;
w9=(1-d9/max(X))^6;
w10=(1-d10/max(X))^6;

