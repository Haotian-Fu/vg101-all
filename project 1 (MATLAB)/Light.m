classdef Light < handle
    properties
        interval
        color
    end
    
    methods
        function ret = Light(color,interval)
            ret.color = color;
            ret.interval = interval;
        end
        
        function draw(light,w)
            hold on
           switch light.color
                case 1
                    plot(4*w,4*w,'o','MarkerSize',14,'MarkerEdgeColor','g','MarkerFaceColor','g');
                    plot(6*w,6*w,'o','MarkerSize',14,'MarkerEdgeColor','g','MarkerFaceColor','g');
                    plot(6*w,4*w,'o','MarkerSize',14,'MarkerEdgeColor','r','MarkerFaceColor','r');
                    plot(4*w,6*w,'o','MarkerSize',14,'MarkerEdgeColor','r','MarkerFaceColor','r');
                case 2
                    plot(4*w,4*w,'o','MarkerSize',14,'MarkerEdgeColor','[1 0.5 0]','MarkerFaceColor','[1 0.5 0]');
                    plot(6*w,6*w,'o','MarkerSize',14,'MarkerEdgeColor','[1 0.5 0]','MarkerFaceColor','[1 0.5 0]');
                    plot(6*w,4*w,'o','MarkerSize',14,'MarkerEdgeColor','[1 0.5 0]','MarkerFaceColor','[1 0.5 0]');
                    plot(4*w,6*w,'o','MarkerSize',14,'MarkerEdgeColor','[1 0.5 0]','MarkerFaceColor','[1 0.5 0]');
                case 3
                    plot(4*w,4*w,'o','MarkerSize',14,'MarkerEdgeColor','r','MarkerFaceColor','r');
                    plot(6*w,6*w,'o','MarkerSize',14,'MarkerEdgeColor','r','MarkerFaceColor','r');
                    plot(6*w,4*w,'o','MarkerSize',14,'MarkerEdgeColor','g','MarkerFaceColor','g');
                plot(4*w,6*w,'o','MarkerSize',14,'MarkerEdgeColor','g','MarkerFaceColor','g');
           end
           hold off
        end
    end
end