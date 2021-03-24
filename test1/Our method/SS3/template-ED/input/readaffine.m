function re_affine_dtidata=readaffine()
[filename pathname] = uigetfile('*.raw','Please select a RAW file');
fid = fopen([pathname filename],'rb');
affine_img=fread(fid,'*float');%����DTI�������ų�һ�У��洢��img��

affine_img=reshape(affine_img,128,128,64);%�������DTI�������г�6*128*128*64�ľ�����ʽ���洢��img��
fclose(fid);
affine_mri=cell(128,128,64);%����128*128*64�Ŀվ���cell,��ֵ��mri���ڴ洢�������ص�9��������������˳��Ϊ
                     %Dxx,Dxy,Dxz,Dyx,Dyy,Dyz,Dzx,Dzy,Dzz
for x=1:128          
     for y=1:128     
        for z=1:64
            affine_mri{x,y,z}=affine_img(x,y,z);            
        end
    end
end

%  for x=1:128          
%      for y=1:128     
%         for z=1:64
%            re_mri=img(:,x,y,z);  
%             re_mri{:,x,y,z}=[re_mri(1) re_mri(4) re_mri(5) re_mri(4) re_mri(2) re_mri(6) re_mri(5) re_mri(6) re_mri(3)];
%         end
%     end
% end
        
            
%%
%dtidata���DTI����
%affine_dtidata=cell(128,128,64);%��mri��ÿ��Ԫ�ص�9����������DTI3*3�Գƾ������ʽ�洢
%re_affine_dtidata=cell(128,128,64);
%for x=1:128
%    for y=1:128
%        for z=1:64
%            affine_dtidata{x,y,z}=[affine_mri{x,y,z}(1,1),affine_mri{x,y,z}(4,1),affine_mri{x,y,z}(5,1);
%                            affine_mri{x,y,z}(4,1),affine_mri{x,y,z}(2,1),affine_mri{x,y,z}(6,1);
%                            affine_mri{x,y,z}(5,1),affine_mri{x,y,z}(6,1),affine_mri{x,y,z}(3,1)];
%             re_affine_dtidata{x,y,z}=reshape(affine_dtidata{x,y,z},3,3);
%       end
%    end
%end



