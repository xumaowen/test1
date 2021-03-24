function re_dtitk_dtidata=readdtitk()
[filename pathname] = uigetfile('*.raw','Please select a RAW file');
fid = fopen([pathname filename],'rb');
dtitk_img=fread(fid,'*float');%����DTI�������ų�һ�У��洢��img��
dtitk_img=reshape(dtitk_img,6,128,128,64);%�������DTI�������г�6*128*128*64�ľ�����ʽ���洢��img��
fclose(fid);
dtitk_mri=cell(128,128,64);%����128*128*64�Ŀվ���cell,��ֵ��mri���ڴ洢�������ص�9��������������˳��Ϊ
                     %Dxx,Dxy,Dxz,Dyx,Dyy,Dyz,Dzx,Dzy,Dzz
for x=1:128          
     for y=1:128     
        for z=1:64
            dtitk_mri{x,y,z}=dtitk_img(:,x,y,z);            
        end
    end
end


%dtidata���DTI����
dtitk_dtidata=cell(128,128,64);%��mri��ÿ��Ԫ�ص�9����������DTI3*3�Գƾ������ʽ�洢
re_dtitk_dtidata=cell(128,128,64);
for x=1:128
    for y=1:128
        for z=1:64
            dtitk_dtidata{x,y,z}=[dtitk_mri{x,y,z}(1,1),dtitk_mri{x,y,z}(4,1),dtitk_mri{x,y,z}(5,1);
                            dtitk_mri{x,y,z}(4,1),dtitk_mri{x,y,z}(2,1),dtitk_mri{x,y,z}(6,1);
                            dtitk_mri{x,y,z}(5,1),dtitk_mri{x,y,z}(6,1),dtitk_mri{x,y,z}(3,1)];
             re_dtitk_dtidata{x,y,z}=reshape(dtitk_dtidata{x,y,z},3,3);
        end
    end
end
