import ch.aplu.turtle.Options;
import ch.aplu.turtle.Turtle;

import java.awt.*;
import java.util.Random;

/**
 * Created by Alex on 1/9/2016.
 */
public class Drawing {

    private static class FernTurtle extends Turtle {
        public FernTurtle(){
            this.hideTurtle();
            this.setColor(Color.orange);
            this.setPenColor(Color.orange);
            this.setPos(-15.0,-100.0);
        }

        public void fern(double size,int generations){
            setColor(Color.orange);
            if (generations > 0 ){
                forward(size);
                right(16);
                fern(size* .8,generations-1);
                left(16);
                back(size* .05 );
                left(40);
                fern(size* .45,generations-1);
                right(40);
                back(size*0.2);
                right(35);
                fern(size * 0.4,generations-1);
                left(35);
                back(size*0.75);
            }
        }

        public String setNextGeneration(String currentGeneration){
            StringBuffer buffer = new StringBuffer();
            String nextGen;
            for(int j = 0; j < currentGeneration.length(); j++){
                char c = currentGeneration.charAt(j);
                if(c == 'X'){
                    buffer.append("F−[[-X]-X-X]+F[+F-X]−X");
                }else if(c == 'F') {
                    buffer.append("FF");
                }
                else
                    buffer.append(c);
            }
            nextGen = buffer.toString();
            return nextGen;
        }

        public void drawLSYstemTree(double len, int generations,int leftAngle, int rightAngle){
            String currentGen = "X";

            for(int i = 0; i < generations; i ++) {
                currentGen = setNextGeneration(currentGen);
            }

            double width = 3.0;

            setLineWidth(width);
            for(int i = 0; i < currentGen.length(); i++){
                char c = currentGen.charAt(i);
                switch (c){
                    case 'F' :
                        width = width*0.88;
                        setLineWidth(width);
                        forward(len);
                        break;
                    case '-' :
                        left(leftAngle);
                        break;
                    case '+' :
                        right(rightAngle);
                        break;
                    case '[' :
                        pushState();
                        break;
                    case ']':
                        popState();
                        break;
                }
            }
        }

        public void tree(double len, double width, int generations){
            setLineWidth(width);
            forward(len);
            if(generations > 0) {
                pushState();
                right(32);
                tree(0.70 * len,width*0.70,generations -1);
                popState();
                pushState();
                left(32);
                tree(0.70 * len, width*0.70, generations -1);
                popState();
            }
        }
    }

    public static void main(String[]args){
        Options.setPlaygroundSize(1200,800);


        int [] angles = {15,17,21,25,27,31,35,40};
        double [] delta = {-5.0,5.0,7.5,-7.5,10.0,-10.0,15.0,-15.0,17.5,-17.5,20.0,-20.0,25.0,-25.0};
        int [] treeWidths = {15,11,13,9,10,12};

        Random r = new Random();

        int treeNr = r.nextInt(23-11) + 11;
        int fernsNr = r.nextInt(10-5) + 5;
        int lsystemNr = r.nextInt(150-120) + 120;

        int segment = 1200/treeNr;
        int fernSegments = 1200/fernsNr;
        int lsystemSegments = 1200/lsystemNr;

        FernTurtle f = new FernTurtle();


        f.setPenColor(Color.BLACK);
        f.setPos(-600,-50);
        f.right(80);
        f.rightArc(5000,70);

        f.setFillColor(new Color(244, 247, 240));
        f.fill(-400,-400);
        f.setFillColor(new Color(184, 186, 196));
        f.fill(0,200);


        for (int i= -600 + segment; i < 600 ; i += segment){
            f.heading(0);
            f.setPenColor(new Color(132, 82, 73));
            double d1 = delta[r.nextInt(delta.length-1) + 1];
            double d2 = delta[r.nextInt(delta.length-1) + 1];
            int treeW = treeWidths[r.nextInt(treeWidths.length-1)+1];
            f.setPos(i+d1,-100+d2);
            f.tree(80+d2,treeW,8);
        }

        for(int i=-600 + fernSegments; i<600;i+=fernSegments){
            f.heading(0);
            f.setPenColor(new Color(190, 216, 98));
            double d1 = delta[r.nextInt(delta.length-1)+1];
            double d2 = delta[r.nextInt(delta.length -1)+1];
            f.setPos(i+d1,-200+d2);
            f.fern(30,6);
        }

        for(int i=-600 + lsystemSegments; i<600;i+=lsystemSegments){
            f.heading(0);
            f.setPenColor(new Color(217, 244, 39));
            double d1 = delta[r.nextInt(delta.length-1)+1];
            double d2 = delta[r.nextInt(delta.length -1)+1];
            int rightAngle = angles[r.nextInt(angles.length-1)+1];
            int leftAngle = angles[r.nextInt(angles.length-1)+1];
            f.setPos(i+d1,-250+(d2*3));
            f.drawLSYstemTree(3,2,leftAngle,rightAngle);
        }

        f.setPenColor(Color.WHITE);

        for(int i = 0; i < 1000; i ++){
            int x = -600 + r.nextInt(1200);
            int y = -400 + r.nextInt(800);
            f.setPos(x,y);
            f.dot(3);
        }
    }

}
