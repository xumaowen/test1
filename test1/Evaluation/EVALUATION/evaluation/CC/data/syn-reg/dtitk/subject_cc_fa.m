% function 

clear all;
clc;
[filename pathname]=uigetfile('.nii');
nii_subject_fa=load_nii(filename,[],1);
% subject_mean_fa=mean2(nii_subject_fa.img);
[filename pathname]=uigetfile('.nii');
nii_template_fa=load_nii(filename,[],1);
% template_mean_fa=mean2(nii_template_fa.img);
% r=corr2(nii_subject_fa.img,nii_subject_fa.img);
%nii_subject_fa.img=double(nii_subject_fa.img);
r_fa=sum( sum(sum(nii_subject_fa.img.*nii_template_fa.img)))/...
    sqrt(sum(sum(sum(nii_subject_fa.img.*nii_subject_fa.img)))*sum(sum(sum(nii_template_fa.img.*nii_template_fa.img))))


