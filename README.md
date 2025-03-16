# Edmonds-Karp Algorithm & Hypercube Graph  

This repository contains an implementation of the **Edmonds-Karp algorithm** in C++ for computing the maximum flow in a flow network. To test the algorithm, a **hypercube graph** is generated and used as an input. Additionally, a **Julia script** is automatically generated for solving the max-flow problem using the **GLPK solver**.  

## Features  
- **Edmonds-Karp Algorithm**: An efficient BFS-based implementation of the Ford-Fulkerson method.  
- **Hypercube Graph**: Used as a structured test case for the max-flow algorithm.  
- **GLPK Solver Script**: A Julia (`.jl`) script that solves the max-flow problem using the **GLPK** optimization package for verification.  

## Usage  
1. Clone the repository:  
   ```bash
   git clone https://github.com/rrubaszek/MaxFlowAlgorithms.git
   cd MaxFlowAlgorithms
   ```
2. Compile and run the program (make required):  
   ```bash
   make
   ./main --size {hypercube dimension}
   (note: it is recommended to provide dimension not highier than 16, as hypercube's size grows exponentially)
   ```
3. Run the Julia solver (requires Julia and GLPK):  
   ```bash
   julia test.jl
   ```

## Dependencies  
- **C++17 or later** (for Edmonds-Karp and hypercube)  
- **Julia** (for the GLPK solver)  
- **GLPK.jl** package (install using `import Pkg; Pkg.add("GLPK")`)  

## License  
This project is licensed under the MIT License.  