V=spm_vol_nifti('template_fa_you_neinang_label.nii');
[Y,XYZ]=spm_read_vols(V);
label_you_neinang=Y;
save('label','label_you_neinang');