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

## bug ที่แก้ไปแล้ว

ทุกไฟล์คอมไพล์ผ่านและไม่เหลือ warning จาก `-Wall -Wextra` ยกเว้นไฟล์ OpenCV ที่ต้องใช้ Windows API

| ไฟล์ | ปัญหาเดิม |
|---|---|
| `dynamic-programming/knapsack_01_memoization.cpp` | พิมพ์ `<<cout` แทน `<<endl` คอมไพล์ไม่ผ่าน |
| `dynamic-programming/running_mean_recursive.cpp` | `findMean` ไม่มี `return` และ memo ตายตัวที่ 50 ช่อง |
| `dynamic-programming/subset_max_count_target_sum.cpp` | memo ใช้ index แค่ `n` ไม่รวมเป้าหมาย, ค่า -1 ที่แปลว่าทำไม่ได้ถูกบวก 1 กลายเป็นคำตอบจริง, และ main เรียกด้วย `n-1` ทำให้ตกตัวสุดท้าย |
| `dynamic-programming/binomial_coefficient_memo.cpp` | เช็ค memo แล้วไม่ `return` memo จึงไม่ถูกใช้เลย |
| `graph/kruskal_mst_weight_sum.cpp` | กราฟที่ไม่เชื่อมกันทำให้อ่าน `pq.top()` ตอน queue ว่างแล้ววนไม่รู้จบ |
| `graph/kruskal_mst_print_edges.cpp` | ปัญหาเดียวกัน |
| `graph/graph_list_bfs_dfs_toolkit.cpp` | ฟังก์ชันนับ connected component ไม่ `return` ค่า |
| `graph/dijkstra_bottleneck_capacity.cpp` | `&&` ปนกับ `||` โดยไม่มีวงเล็บ |
| `backtracking/max_value_non_adjacent_subset.cpp` | อ่าน `A[-1]` เมื่อ `l == 0` |
| `backtracking/subset_sum_backtracking.cpp` | recursion ส่ง `l+1` แทน `i+1` ทำให้พิมพ์ subset ซ้ำ |
| `backtracking/n_queens_bruteforce.cpp` | นับทุก leaf (256 สำหรับ n=4) แทนที่จะนับเฉพาะคำตอบที่ถูก (2) |
| `greedy/v2_7_3_pair_max_sum.cpp` | อ่านเกินขอบ array เมื่อ n เป็นเลขคี่ และมี `i=i+1` เกินมาทำให้ข้ามค่า |
| `searching/binary_search_recursive.cpp` | `l<r` ทำให้ไม่เคยตรวจช่วงที่เหลือตัวเดียว และไม่ `return` เมื่อหาไม่เจอ |
| `searching/interpolation_search.cpp` | หารด้วยศูนย์เมื่อ `A[l]==A[r]` และไม่ `return` เมื่อหาไม่เจอ |
| `searching/hw2_1_interpolation_search.cpp` | recursion ไม่รู้จบเมื่อหาไม่เจอ, หารด้วยศูนย์, ไม่ `return` |
| `linked-list/doubly_linked_list.cpp` | `push` เขียน `head->prev` ก่อนอ่าน ทำให้ `x->prev` ชี้กลับหาตัวเอง |
| `numerical-methods/false_position_nth_root.cpp` | `double xL = xL = 0` เป็น undefined behavior |

## ข้อจำกัดที่เหลือ

- `misc/opencv_screen_motion_autokey.cpp` ต้องใช้ OpenCV และ Windows API คอมไพล์บน Linux ไม่ได้
- `graph/dijkstra_bottleneck_capacity.cpp` เงื่อนไข `|| V==end` เทียบจำนวน vertex กับปลายทาง ดูไม่สมเหตุสมผล ผมใส่วงเล็บให้ตรงกับพฤติกรรมเดิมไว้ก่อน ยังไม่ได้เดาว่าโจทย์ต้องการอะไร
