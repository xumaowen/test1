function tem_re_dtidata=readtemplate()
%��ȡģ������
[filename pathname] = uigetfile('*.raw','Please select a RAW file');
fid = fopen([pathname filename],'rb');
tem=fread(fid,'*float');%����DTI�������ų�һ�У��洢��img��
tem=reshape(tem,6,256,256,256);%�������DTI�������г�9*128*128*64�ľ�����ʽ���洢��img��
fclose(fid);
tem_mri=cell(256,256,256);%����128*128*64�Ŀվ���cell,��ֵ��mri���ڴ洢�������ص�9��������������˳��Ϊ
                     %Dxx,Dxy,Dxz,Dyx,Dyy,Dyz,Dzx,Dzy,Dzz
for x=1:256          
     for y=1:256   
        for z=1:256
            tem_mri{x,y,z}=tem(:,x,y,z);
        end
    end
end
%dtidata���DTI����
tem_dtidata=cell(256,256,256);%��mri��ÿ��Ԫ�ص�9����������DTI3*3�Գƾ������ʽ�洢
tem_re_dtidata=cell(256,256,256);
for x=1:256
    for y=1:256
        for z=1:256
            tem_dtidata{x,y,z}=[tem_mri{x,y,z}(1,1),tem_mri{x,y,z}(4,1),tem_mri{x,y,z}(5,1);
                            tem_mri{x,y,z}(4,1),tem_mri{x,y,z}(2,1),tem_mri{x,y,z}(6,1);
                            tem_mri{x,y,z}(5,1),tem_mri{x,y,z}(6,1),tem_mri{x,y,z}(3,1)];
             tem_re_dtidata{x,y,z}=reshape(tem_dtidata{x,y,z},3,3);
        end
    end
end