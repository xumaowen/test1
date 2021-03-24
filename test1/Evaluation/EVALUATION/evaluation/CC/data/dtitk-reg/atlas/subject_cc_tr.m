% function
clear all;
clc;
[filename pathname]=uigetfile('.nii');
nii_subject_tr=load_nii(filename,[],1);

[filename pathname]=uigetfile('.nii');
nii_template_tr=load_nii(filename,[],1);

% r=corr2(nii_subject_fa.img,nii_subject_fa.img);
r_tr=sum( sum(sum(nii_subject_tr.img.*nii_template_tr.img)))/...
    sqrt(sum(sum(sum(nii_subject_tr.img.*nii_subject_tr.img)))*sum(sum(sum(nii_template_tr.img.*nii_template_tr.img))))
