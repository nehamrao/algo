/*Convex Hull - Graham Scan
-------------------------

1. Find the lowest y point, choose leftmost if same y's --> O(n)
2. Sort points from this lowest y point, based on below: --> O(nlogn)

        
    *(x3,y3)
        *(x2,y2)
    *(x1,y1)    
    
    
    sigma = (x2-x1)/(y2-y1)
    phi   = (x3-x2)/(y3-y2)
    
    if sigma < phi ==> Counter-clockwise/left turn 
    if sigma > phi ==> Clockwise/right turn
    if sigma == phi ==> Same line, no turn
    
    Hence diff --> (x2-x1)*(x3-x2) - (y2-y1)*(y3-y2) 
       diff > 0 ==>Clockwise
       diff < 0 ==> Counter-clockwise
       diff == 0 ==> Collinear
       
    Use quick sort with a compare API like below
    
    int compare (const void* p1, const void* p2);

	> Taking two pointers as arguments (both converted to const void*). The function defines the order of the elements by returning (in a stable and transitive manner):
return value	meaning
    < 0	The element pointed to by p1 goes before the element pointed to by p2
      0	The element pointed to by p1 is equivalent to the element pointed to by p2
    > 0	The element pointed to by p1 goes after the element pointed to by p2


 One more optimization is that if two points have the same angle, we will use only the one that is furthest
 
3. Now from the lowest y point selected, to each point in the sorted vector, determine
the nature of the turn (a counter clockwise turn implies, it could be on the convex hull)

> Reuse the previous turn determinig API

4. Now use a stack and push the first three points in the vector (If less than 3 then cannot form hull)
   > Then compare the slopes of the prev to top of stak, the top of stack and the current point (from 4th point onwards) using the previous orientation API and verfiy if it is a counter clockwise turn. If not, then pop from stack and push current point --> O(n)

Worst case time complexity --> O(nlogn)

*/


class ConvexHull {
  public:
    
    ConvexHull (vector<int> &x_axis, vector<int> &y_axis) {
        if (x_axis.size() != y_axis.size()) {
            cout << "Invalid input!";
        } else if (x_axis.size() == y_axis.size()) {
            for (int i = 0; i < x_axis.size(); i++) {
               Point p;
                p.x = x_axis[i];
                p.y = y_axis[i];
                graph.push_back(p);
            }
        }   
    }
    
    class Point {
        int x;
        int y;
    };
    
    vector<Point> getConvexHullPoints () {
        
        
        vector<Point> result;
        
        // Trivial case
        if (graph.size() = 0) {
            return result;
        }
        
        // Get leftmost y point
        int ymin = graph[0].y;
        int xmin = graph[0].x;
        
        int ymin_idx = 0;
        for (int i = 1; i < graph.size(); i++) {
            if (graph[i].y < ymin) {
                ymin = graph[i].y;
                xmin = graph[i].x;
                ymin_idx = i;    
            } else if (graph[i].y == ymin){
                // Same y for two points, choose leftmost
                if (graph[i].x < xmin) {
                    ymin = graph[i].y;
                    xmin = graph[i].x;
                }
            }
        }
        
        // Swap the point with min y with first in the input graph
        Point temp = graph[0];
        graph[0] = graph[i];
        graph[i] = temp;
        
        // Sorting points based on lowest y point, note that we start from 2nd element
        qsort(&graph[1], graph.size() - 1, sizeof(Point), compare);
        
        // Of the sorted points, we must eliminate the ones which have same angle wrt first point
        // Optimization?
        
        if (graph.size() < 3) {
            return result;
        }
        
        stack<Point> stk;
        stk.push(graph[0]);
        stk.push(graph[1]);
        stk.push(graph[2]);
        
        for (int i = 3; i < graph.size(); i++) {
            // Keep removing top while the angle formed by
            // points prev-to-top, top, and points[i] makes
            // a non-left turn
            while (getOrientation(getPrevToTopOfStack(), skt.top(), graph[i]) != COUNTERCLOCKWISE) {
                // Not counter-clockwise
                stk.pop();
            }
            stk.push(graph[i]);
        }
        
        // Transfer the stk Points to result vector
        while (!stk.empty()) {
            result.push_back(stk.pop());
        }
        
        return result;
    }
    
  private:
    
    vector<Point> graph;
        
    enum Dir {
      CLOCKWISE = 1,
      COUNTERCLOCKWISE = -1,
      COLINEAR = 0,
    };
    
    
    int getDist (Point a, Point b) {
        return (b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y);    
    }
    
    int getOrientation (Point a, Point b, Point c) {
         int slope_diff = (b.x - a.x)*(c.y-b.y) - (c.x - b.x)*(b.y = a.y);
        
         if (slope_diff > 0) {
             // Clockwise
             return  CLOCKWISE;
         } else if (slope_diff < 0) {
             return COUNTERCLOCKWISE;
         } 
        
         return COLINEAR;
    }
    
    int compare (const void* a, const void* b) {
        Point *p1 = (Point *) a;
        Point *p2 = (Point *) b;
        
        int dir = getOrientation(graph[0], *p1, *p2);
        if (dir == CLOCKWISE) {
            return 1;
        } else if (dir == COUNTERCLOCKWISE) {
            return -1;
        } else {
            // For collinear pts, choose one that is furthest
            if (getDist(graph[0], *p1) >= getDist(graph[0], *p2)) {
                return -1;
            }
        }
        
        return 0;
        
    }
    
    Point getPrevToTopOfStack (stack<Point> &stk) {
        Point res;
        
        if (!stk.empty()) {
            Point temp = stk.top();
            stk.pop();
            res = stk.top();
            stk.push(temp);
            
            return res;
        }
        
        return res;
    }
    
    
};
    