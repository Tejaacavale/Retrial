# RETRIAL QUEUE SIMULATOR
![Queue Diagram](/retrial.png)

## OVERVIEW
The project covers various concepts related to retrial queues, specifically focusing on M/M/1 and M/M/K models. Here is a summary of the key concepts discussed in the report:

1. **Introduction to Retrial Queues**:
   - A retrial queue consists of servers and a queue where customers arrive according to a Poisson process.
   - Primary calls are served immediately if the server is free, otherwise, they join the queue and may generate repeated calls.
   - Repeated calls form a Poisson process, and there may be a limit on the number of retries.

2. **Notation**:
   - Key parameters include arrival rate of primary calls (λ), rate of repeated calls (μ), service distribution (B(x)), number of busy servers (C(t)), number of sources of repeated calls (N(t)), and age of the current process (ξ(t)).
   - Definitions of Laplace transform of service time, hazard rate, and distribution of the number of primary calls that arrive during service time are provided.

3. **M/M/1 Retrial Queue**:
   - Service time distribution in M/M/1 retrial queue is defined as $B(x) = 1 - e^{-νx}$.
   - Continuous-Time Markov Chain (CTMC) states are represented by (C(t), N(t)), where C(t) indicates the number of busy servers.

4. **Performance Metrics**:
   - Metrics include mean number of jobs in the queue and system, mean sojourn time, blocking probability, recurrence conditions, and mean number of retrials per job.
   - Formulas for calculating these metrics are provided along with proofs for stationary distributions.

5. **M/M/K Model**:
   - Description of the M/M/K model where a group of c fully available servers handle primary calls.
   - If all servers are busy, a source of repeated calls is generated, which follows an exponential distribution for retrial periods.
   - The system is described using a bivariate process (C(t), N(t)), with a generator matrix defining transition rates.

Overall, the project delves into the theoretical foundations, mathematical formulations, and performance evaluation of retrial queues, providing insights into the behavior and analysis of these queueing systems.

![CTMC](/states.jpeg)
## CONTRIBUTORS
This was a group project done by:
- Aditya Mishra
- Hardik Kalia
- Shreyas Adiga
- Tejas Cavale


