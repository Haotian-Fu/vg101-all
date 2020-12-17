classdef Car < handle
   properties
       position
       size
       plate
       possibility
       direction
       length
       width
       jumpred
       motion
   end
   methods
       function ret = Car(position,size,possibility,direction,motion)
           ret.position = position;
           ret.direction = direction;
           ret.size = size;
           ret.possibility = possibility;
           ret.motion = motion;
       end
       
       function draw(ret) 
           switch ret.direction 
               case Direction.Left
                    rectangle('Position',[ret.position ret.size],'FaceColor','m');
               case Direction.Right
                    rectangle('Position',[ret.position ret.size],'FaceColor','g');
               case Direction.Up
                    rectangle('Position',[ret.position ret.size],'FaceColor','y');
               case Direction.Down
                    rectangle('Position',[ret.position ret.size],'FaceColor','c');
           end
       end
       
       function move(ret,w)
           switch ret.direction 
               case Direction.Left
                    ret.position(1) = ret.position(1)+0.1*w;
               case Direction.Right
                    ret.position(1) = ret.position(1)-0.1*w;
               case Direction.Up
                    ret.position(2) = ret.position(2)-0.1*w;
               case Direction.Down
                    ret.position(2) = ret.position(2)+0.1*w;
           end
       end
       
       function retnew=remove(ret,w)
           switch ret.direction 
               case Direction.Left
                    ret.position(1) = ret.position(1)-0.1*w;
               case Direction.Right
                    ret.position(1) = ret.position(1)+0.1*w;
               case Direction.Up
                    ret.position(2) = ret.position(2)+0.1*w;
               case Direction.Down
                    ret.position(2) = ret.position(2)-0.1*w;
           end
           ret.motion = 0;
           retnew=ret;
       end
       
       function plate4(ret)
            x = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ';
            y = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789';  
            ret.plate='      ';
            ret.plate(1)=x(randi(26));
            perm = randperm(36,5);
            for i=1:5
                ret.plate(i+1)=y(perm(i));
            end
       end
       
       function tmp=plategen(org,n,y)
          if n==0 
              tmp=[]; 
          else
              i=randi(31+n);
              tmp=y(i)+org.plategen(n-1,setdiff(y(i),y));
          end
       end
       
       function randsize(ret)
           while true
                a = rand;
                if a <=0.8 && a>=0.4
                    ret.size(1) = a*ret.size(1);
                    ret.size(2) = a*ret.size(2);
                    break
                end
           end
       end
       
       function jump(ret)
           ret.jumpred = rand;
       end
       
       function violate(ret)
                disp('violated car plates:');
                disp(ret.plate);
       end
       
       function lengwid(ret)
          ret.length = [ret.position(1) ret.position(1)+ret.size(1)];
          ret.width = [ret.position(2) ret.position(2)+ret.size(2)];
       end
       
       
   end      
end