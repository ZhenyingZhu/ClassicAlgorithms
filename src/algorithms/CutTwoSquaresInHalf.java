package algorithms.mathandprob; 

import java.util.*; 

public class CutTwoSquaresInHalf {
    /* Function: Implement a square class that can make a longest line to cut another square in half. 
     * Solution: Through two middle points. Notice it is square, so when slope == 1, it reach two vertex. 
     */ 
    
    /* Test Case 
    public static void main(String[] args) {
        Square s1 = new Square(0, 5, 5, 0); 
        Square s2 = new Square(5, 10, 10, 5); 
        System.out.println(s1.cut(s2)); 
    }
    */
}

class Square {
    double left, right, top, bottom; 
    public Square(double l, double r, double t, double b) {
        left = l; 
        right = r; 
        top = t; 
        bottom = b; 
    }
    
    public Line cut(Square other) {
        if (other == null || (this.left == other.left && this.right == other.right && this.top == other.top && this.bottom == other.bottom)) {
            return null; 
        }
        
        Point m1 = mid(this), m2 = mid(other); 
        Point p1 = null, p2 = null; 

        if (m1.x == m2.x) {
            if (this.top > other.top) {
                p1 = new Point(m1.x, this.top); 
                p2 = new Point(m2.x, other.bottom); 
            } else {
                p1 = new Point(m1.x, this.bottom); 
                p2 = new Point(m2.x, other.top); 
            }
            return new Line(p1, p2); 
        }
        
        double slope = (m1.y - m2.y) / (m1.x - m2.x); 
        double insert = m1.y - slope * m1.x; 

        if (slope == 0) {
            if (this.left < other.left) {
                p1 = new Point(this.left, m1.y); 
                p2 = new Point(other.right, m2.y); 
            } else {
                p1 = new Point(other.left, m2.y); 
                p2 = new Point(this.right, m1.y); 
            }
        } else if (Math.abs(slope) > 1) {
            if (this.top > other.top) {
                p1 = new Point((this.top - insert) / slope, this.top); 
                p2 = new Point((other.bottom - insert) / slope, other.bottom); 
            } else {
                p1 = new Point((other.top - insert) / slope, other.top); 
                p2 = new Point((this.bottom - insert) / slope, this.bottom); 
            }
        } else {
            if (this.left < other.left) {
                p1 = new Point(this.left, slope * this.left + insert); 
                p2 = new Point(other.right, slope * other.right + insert); 
            } else {
                p1 = new Point(other.left, slope * other.left + insert); 
                p2 = new Point(this.right, slope * this.right + insert); 
            }
        }
        
        return new Line(p1, p2); 
    }
    
    private Point mid(Square sqe) {
        return new Point((sqe.left + sqe.right) / 2, (sqe.bottom + sqe.top) / 2); 
    }
}

class Point {
    double x, y; 
    public Point(double x, double y) {
        this.x = x; 
        this.y = y; 
    }
    
    public String toString() {
        return "(" + x + ", " + y + ")"; 
    }
}

class Line {
    Point p1, p2; 
    public Line(Point p1, Point p2) {
        this.p1 = p1; 
        this.p2 = p2; 
    }
    
    public String toString() {
        return "<" + p1 + " " + p2 + ">"; 
    }
}