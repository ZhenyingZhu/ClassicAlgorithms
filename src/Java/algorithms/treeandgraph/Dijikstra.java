package algorithms.treeandgraph; 

import java.util.*; 

class Vertex implements Comparable<Vertex> {
    protected String name; 
    List<Edge> neighbors = new ArrayList<Edge>(); 
    protected int distance = Integer.MAX_VALUE; 
    
    public Vertex(String name) {
        this.name = name; 
    }
    
    public int compareTo(Vertex v) {
        return this.distance - v.distance; 
    }
    
    public String toString() {
        return "name: " + name + ",dis: " + distance + ". "; 
    }
}
    
class Edge {
    protected Vertex st; 
    protected Vertex ed; 
    protected int weight; 
    public Edge(Vertex st, Vertex ed, int weight) {
        this.st = st; 
        this.ed = ed; 
        this.weight = weight; 
    }
}
    
public class Dijikstra {
    /* Function: Find all the shortest paths to vertexes from an original point. 
     * Solution: Dijikstra Algorithm. 
     */ 
    
    public List<Vertex> dijikstra(Vertex st) {
        List<Vertex> res = new ArrayList<Vertex>(); 
        if (st == null) {
            return res; 
        }
        
        Queue<Vertex> queue = new PriorityQueue<Vertex>(); 
        st.distance = 0; 
        queue.offer(st); 
        while (!queue.isEmpty()) {
            Vertex v = queue.poll(); 
            res.add(v); 
            for (Edge e : v.neighbors) {
                int dis = v.distance + e.weight; 
                if (dis < e.ed.distance) {
                    queue.remove(e.ed); 
                    e.ed.distance = dis; 
                    queue.offer(e.ed); 
                }
            }
        }
        
        return res; 
    }
    
    /* Test case: 
    public static void main(String[] args) {
        Vertex v0 = new Vertex("0"); 
        Vertex v1 = new Vertex("1"); 
        Vertex v2 = new Vertex("2"); 
        Vertex v3 = new Vertex("3"); 
        Edge e01 = new Edge(v0, v1, 1);
        Edge e02 = new Edge(v0, v2, 1); 
        Edge e12 = new Edge(v1, v2, 1);
        Edge e13 = new Edge(v1, v3, 1);
        Edge e23 = new Edge(v2, v3, 1);
        v0.neighbors.add(e01); 
        v0.neighbors.add(e02); 
        v1.neighbors.add(e12); 
        v1.neighbors.add(e13); 
        v2.neighbors.add(e23); 
        
        List<Vertex> list = new Test().dijikstra(v0); 
        System.out.println(list); 
    }
    */
}
