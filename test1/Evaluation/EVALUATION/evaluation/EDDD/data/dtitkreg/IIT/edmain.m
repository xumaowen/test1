clear all;
clc
%º∆À„≈∑ Ωæ‡¿Î
tem_re_dtidata=readtemplate();
re_dtitk1_dtidata=readdtitk();
re_dtitk2_dtidata=readdtitk();
re_dtitk3_dtidata=readdtitk();
re_dtitk4_dtidata=readdtitk();
re_dtitk5_dtidata=readdtitk();
re_dtitk6_dtidata=readdtitk();
re_dtitk7_dtidata=readdtitk();
re_dtitk8_dtidata=readdtitk();
re_dtitk9_dtidata=readdtitk();
re_dtitk10_dtidata=readdtitk();

dtitk_dist1=zeros(128,128,64);
dtitk_dist2=zeros(128,128,64);
dtitk_dist3=zeros(128,128,64);
dtitk_dist4=zeros(128,128,64);
dtitk_dist5=zeros(128,128,64);
dtitk_dist6=zeros(128,128,64);
dtitk_dist7=zeros(128,128,64);
dtitk_dist8=zeros(128,128,64);
dtitk_dist9=zeros(128,128,64);
dtitk_dist10=zeros(128,128,64);
for x=1:256          
     for y=1:256   
        for z=1:256
            dtitk_dist1(x,y,z)=norm(re_dtitk1_dtidata{x,y,z}-tem_re_dtidata{x,y,z});
        end
    end
end
for x=1:256          
     for y=1:256   
        for z=1:256
            dtitk_dist2(x,y,z)=norm(re_dtitk2_dtidata{x,y,z}-tem_re_dtidata{x,y,z});
        end
    end
end
for x=1:256          
     for y=1:256   
        for z=1:256
            dtitk_dist3(x,y,z)=norm(re_dtitk3_dtidata{x,y,z}-tem_re_dtidata{x,y,z});
        end
    end
end
for x=1:256          
     for y=1:256   
        for z=1:256
            dtitk_dist4(x,y,z)=norm(re_dtitk4_dtidata{x,y,z}-tem_re_dtidata{x,y,z});
        end
    end
end
for x=1:256          
     for y=1:256   
        for z=1:256
            dtitk_dist5(x,y,z)=norm(re_dtitk5_dtidata{x,y,z}-tem_re_dtidata{x,y,z});
        end
    end
end
for x=1:256          
     for y=1:256   
        for z=1:256
            dtitk_dist6(x,y,z)=norm(re_dtitk6_dtidata{x,y,z}-tem_re_dtidata{x,y,z});
        end
    end
end
for x=1:256          
     for y=1:256   
        for z=1:256
            dtitk_dist7(x,y,z)=norm(re_dtitk7_dtidata{x,y,z}-tem_re_dtidata{x,y,z});
        end
    end
end
for x=1:256          
     for y=1:256   
        for z=1:256
            dtitk_dist8(x,y,z)=norm(re_dtitk8_dtidata{x,y,z}-tem_re_dtidata{x,y,z});
        end
    end
end
for x=1:256          
     for y=1:256   
        for z=1:256
            dtitk_dist9(x,y,z)=norm(re_dtitk9_dtidata{x,y,z}-tem_re_dtidata{x,y,z});
        end
    end
end
for x=1:256          
     for y=1:256   
        for z=1:256
            dtitk_dist10(x,y,z)=norm(re_dtitk10_dtidata{x,y,z}-tem_re_dtidata{x,y,z});
        end
    end
end



sum=dtitk_dist1+dtitk_dist2+dtitk_dist3+dtitk_dist4+dtitk_dist5+dtitk_dist6+dtitk_dist7...
    +dtitk_dist8+dtitk_dist9+dtitk_dist10;
IIT_ed_dist=sum/10;
save IIT_ed_dist IIT_ed_dist;




 
 