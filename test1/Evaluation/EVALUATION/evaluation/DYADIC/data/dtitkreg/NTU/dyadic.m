clear all;
clc;
% affine_fa
[filename pathname]=uigetfile('*.nii');
% [affine_fa_hdr, affine_fa_filetype, affine_fa_fileprefix, affine_fa_machine]=load_nii_hdr(filename);
% [affine_fa_img,affine_fa_hdr]=load_nii_img(affine_fa_hdr,affine_fa_filetype,affine_fa_fileprefix,affine_fa_machine,[],1);
affine_s1=load_nii(filename,[],1);
[filename pathname]=uigetfile('*.nii');
affine_s2=load_nii(filename,[],1);
[filename pathname]=uigetfile('*.nii');
affine_s3=load_nii(filename,[],1);
[filename pathname]=uigetfile('*.nii');
affine_s4=load_nii(filename,[],1);
[filename pathname]=uigetfile('*.nii');
affine_s5=load_nii(filename,[],1);
[filename pathname]=uigetfile('*.nii');
affine_s6=load_nii(filename,[],1);
[filename pathname]=uigetfile('*.nii');
affine_s7=load_nii(filename,[],1);
[filename pathname]=uigetfile('*.nii');
affine_s8=load_nii(filename,[],1);
[filename pathname]=uigetfile('*.nii');
affine_s9=load_nii(filename,[],1);
[filename pathname]=uigetfile('*.nii');
affine_s10=load_nii(filename,[],1);
affine_dycoh=zeros(128,128,64);
 for x=1:256
    for y=1:256
        for z=1:256
     NTU_dycoh(x,y,z)=(affine_s1.img(x,y,z)+affine_s2.img(x,y,z)+affine_s3.img(x,y,z)+affine_s4.img(x,y,z)+affine_s5.img(x,y,z)+...
    affine_s6.img(x,y,z)+affine_s7.img(x,y,z)+affine_s8.img(x,y,z)+affine_s9.img(x,y,z)+affine_s10.img(x,y,z))/10;
        end
    end
 end
 
 save NTU_dycoh NTU_dycoh;