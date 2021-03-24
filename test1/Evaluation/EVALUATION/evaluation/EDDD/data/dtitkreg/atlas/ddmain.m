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


for x=1:128
    for y=1:128
        for z=1:64
            template_dist(x,y,z)=norm(tem_re_dtidata{x,y,z}-(trace(tem_re_dtidata{x,y,z}))*eye(3));
        end
    end
end
for x=1:128
    for y=1:128
        for z=1:64
            dtitk_dist1(x,y,z)=norm(re_dtitk1_dtidata{x,y,z}-(trace(re_dtitk1_dtidata{x,y,z}))*eye(3));
        end
    end
end
for x=1:128
    for y=1:128
        for z=1:64
            dtitk_dist2(x,y,z)=norm(re_dtitk2_dtidata{x,y,z}-(trace(re_dtitk2_dtidata{x,y,z}))*eye(3));
        end
    end
end
for x=1:128
    for y=1:128
        for z=1:64
            dtitk_dist3(x,y,z)=norm(re_dtitk3_dtidata{x,y,z}-(trace(re_dtitk3_dtidata{x,y,z}))*eye(3));
        end
    end
end
for x=1:128
    for y=1:128
        for z=1:64
            dtitk_dist4(x,y,z)=norm(re_dtitk4_dtidata{x,y,z}-(trace(re_dtitk4_dtidata{x,y,z}))*eye(3));
        end
    end
end
for x=1:128
    for y=1:128
        for z=1:64
            dtitk_dist5(x,y,z)=norm(re_dtitk5_dtidata{x,y,z}-(trace(re_dtitk5_dtidata{x,y,z}))*eye(3));
        end
    end
end
for x=1:128
    for y=1:128
        for z=1:64
            dtitk_dist6(x,y,z)=norm(re_dtitk6_dtidata{x,y,z}-(trace(re_dtitk6_dtidata{x,y,z}))*eye(3));
        end
    end
end
for x=1:128
    for y=1:128
        for z=1:64
            dtitk_dist7(x,y,z)=norm(re_dtitk7_dtidata{x,y,z}-(trace(re_dtitk7_dtidata{x,y,z}))*eye(3));
        end
    end
end
for x=1:128
    for y=1:128
        for z=1:64
            dtitk_dist8(x,y,z)=norm(re_dtitk8_dtidata{x,y,z}-(trace(re_dtitk8_dtidata{x,y,z}))*eye(3));
        end
    end
end
for x=1:128
    for y=1:128
        for z=1:64
            dtitk_dist9(x,y,z)=norm(re_dtitk9_dtidata{x,y,z}-(trace(re_dtitk9_dtidata{x,y,z}))*eye(3));
        end
    end
end
for x=1:128
    for y=1:128
        for z=1:64
            dtitk_dist10(x,y,z)=norm(re_dtitk10_dtidata{x,y,z}-(trace(re_dtitk10_dtidata{x,y,z}))*eye(3));
        end
    end
end



sum=dtitk_dist1+dtitk_dist2+dtitk_dist3+dtitk_dist4+dtitk_dist5+dtitk_dist6+dtitk_dist7...
    +dtitk_dist8+dtitk_dist9+dtitk_dist10;
ave_de_dist=sum/10;
atlas_dd_dist=ave_de_dist-template_dist;
save atlas_dd_dist atlas_dd_dist;




 
 