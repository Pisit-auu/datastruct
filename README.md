# Data Structures & Algorithms — Coursework

โค้ด C++ จากวิชา Data Structures, Algorithm Analysis และ Numerical Methods
จัดกลุ่มตามหัวข้อ ชื่อไฟล์บอกสิ่งที่โค้ดทำจริง

## โครงสร้าง

```
data-structures/     โครงสร้างข้อมูลพื้นฐาน
  linked-list/       singly / doubly linked list
  stack/             stack (STL, array, linked list) + งานที่ใช้ stack
  queue/             queue (STL, array, circular, linked list)
  tree/              BST และ AVL
  heap/              max heap / min heap แบบ array
  hash/              hash table แบบ separate chaining
  graph/             adjacency list / adjacency matrix พร้อม DFS, BFS

algorithms/          วิชา Algorithm Analysis
  sorting/           bubble, insertion, selection, merge, quick, shell, counting, radix
  searching/         binary search, interpolation search, quick select
  divide-and-conquer/ max subarray, count inversions, Karatsuba, Strassen
  brute-force/       โจทย์การบ้านที่ใช้ brute force และ recursion พื้นฐาน
  dynamic-programming/ knapsack, binomial, grid path, Floyd-Warshall
  greedy/            fractional knapsack, interval scheduling, CPU scheduling
  graph/             BFS, DFS, Dijkstra, Prim, Kruskal, flood fill
  backtracking/      subset, permutation, combination, n-queens
  stl-basics/        ตัวอย่างการใช้ pair และ priority_queue

numerical-methods/   bisection, false position, fixed point iteration
misc/                โค้ดที่ไม่เข้าหมวดข้างบน
```

## การคอมไพล์

```bash
g++ -std=gnu++11 -o program path/to/file.cpp
./program
```

ทุกไฟล์เป็นโปรแกรมเดี่ยวที่มี `main()` ของตัวเอง ไม่มีการ include ข้ามไฟล์

## หมายเหตุ

- ไฟล์ `.exe` ที่คอมไพล์แล้วไม่ถูกเก็บใน git ดู `.gitignore`
- ไฟล์ 5 ไฟล์มีคอมเมนต์ภาษาไทยที่บันทึกด้วย encoding TIS-620 จึงอ่านเป็นตัวอักษรเพี้ยนในโปรแกรมที่คาดหวัง UTF-8

## bug ที่ยังค้างอยู่ในโค้ด

ตรวจพบตอนจัดระเบียบ ยังไม่ได้แก้เพื่อคงเนื้อหาโค้ดเดิมไว้ ถ้าจะเอาไฟล์เหล่านี้ไปใช้อ้างอิงควรแก้ก่อน

| ไฟล์ | ปัญหา |
|---|---|
| `algorithms/dynamic-programming/knapsack_01_memoization.cpp` | บรรทัด 32 พิมพ์ `<<cout` แทน `<<endl` คอมไพล์ไม่ผ่าน |
| `algorithms/dynamic-programming/running_mean_recursive.cpp` | `findMean` ประกาศเป็น `double` แต่ไม่มี `return` ผลลัพธ์ไม่แน่นอน |
| `algorithms/dynamic-programming/subset_max_count_target_sum.cpp` | memo ใช้ index แค่ `n` ไม่รวมค่าเป้าหมาย ทำให้ค่าที่ต่างกันชนกัน |
| `algorithms/graph/kruskal_mst_weight_sum.cpp` | บรรทัด 33 เริ่ม `ne = 1` จึงรับ edge แค่ V-2 เส้น ขาดไป 1 เส้น |
| `algorithms/backtracking/max_value_non_adjacent_subset.cpp` | อ่าน `A[-1]` เมื่อ `l == 0` |
| `algorithms/backtracking/subset_sum_backtracking.cpp` | recursion ส่ง `l+1` แทนที่จะเป็น `i+1` |
| `algorithms/greedy/v2_7_3_pair_max_sum.cpp` | อ่านเกินขอบ array เมื่อ n เป็นเลขคี่ |
| `misc/opencv_screen_motion_autokey.cpp` | ต้องใช้ OpenCV และ Windows API คอมไพล์บน Linux ไม่ได้ |

เวอร์ชันที่ถูกต้องของ Kruskal อยู่ที่ `algorithms/graph/kruskal_mst_print_edges.cpp`
