# Mô tả các thuật toán đọc đĩa trong hệ điều hành

Dưới đây là mô tả của một số thuật toán đọc đĩa phổ biến trong hệ điều hành:

### 1. **First-Come, First-Served (FCFS)**:

- **Cách thức hoạt động:** Các yêu cầu được xử lý theo thứ tự mà chúng đến. Điều này có nghĩa là yêu cầu được đưa vào hàng chờ trước sẽ được xử lý trước.
- **Ưu điểm:** Đơn giản, dễ hiểu và dễ triển khai.
- **Nhược điểm:** Không hiệu quả khi có nhiều yêu cầu đến từ các vị trí không liên tiếp trên đĩa.

### 2. **Shortest Seek Time First (SSTF)**:

- **Cách thức hoạt động:** Chọn yêu cầu có thời gian đợi (seek time) ngắn nhất từ vị trí hiện tại của đầu đọc/ghi.
- **Ưu điểm:** Hiệu quả hơn FCFS vì giảm thời gian đợi trung bình.
- **Nhược điểm:** Có thể gây ra hiện tượng starvation (một số yêu cầu không được phục vụ vì luôn có yêu cầu mới gần nhất).

### 3. **SCAN (Elevator)**:

- **Cách thức hoạt động:** Đầu đọc/ghi di chuyển từ một đầu của đĩa đến đầu còn lại, và xử lý yêu cầu trên đường đi. Khi đến cuối đĩa, đầu đọc/ghi quay ngược lại.
- **Ưu điểm:** Đảm bảo mọi yêu cầu đều được xử lý, không gây ra starvation.
- **Nhược điểm:** Có thể dẫn đến thời gian chờ lớn nếu có nhiều yêu cầu ở hai đầu của đĩa.

### 4. **C-SCAN (Circular SCAN)**:

- **Cách thức hoạt động:** Giống như SCAN, nhưng chỉ quét một chiều và quay vòng tròn khi đến cuối đĩa để xử lý yêu cầu.
- **Ưu điểm:** Giảm thời gian chờ so với SCAN.
- **Nhược điểm:** Có thể có sự chậm trễ đối với các yêu cầu ở phía bên kia của đĩa.

### 5. **LOOK**:

- **Cách thức hoạt động:** Tương tự như SCAN, nhưng chỉ di chuyển đến cuối đĩa nếu không còn yêu cầu nào ở hướng đó, không cần quay vòng như SCAN.
- **Ưu điểm:** Giảm thời gian chờ so với SCAN vì không cần phải quay vòng khi không có yêu cầu.
- **Nhược điểm:** Có thể gây ra hiện tượng starvation nếu có yêu cầu liên tục đến từ một hướng.

Các thuật toán này đều có ứng dụng trong việc quản lý và tối ưu hóa việc truy cập đĩa trong hệ điều hành. Sự lựa chọn của thuật toán thường phụ thuộc vào yêu cầu cụ thể của hệ thống và môi trường hoạt động.

## Ví dụ:

# Mô tả chi tiết các thuật toán đọc đĩa trong hệ điều hành

Dưới đây là mô tả chi tiết về cách hoạt động của mỗi thuật toán đọc đĩa, cùng với minh họa qua file markdown:

### 1. **First-Come, First-Served (FCFS)**:

- **Cách thức hoạt động:** Các yêu cầu được xử lý theo thứ tự chúng đến.

- **Mô tả chi tiết:**

  - Bắt đầu từ vị trí hiện tại của đầu đọc/ghi.
  - Xử lý các yêu cầu theo thứ tự chúng đến, không quan tâm đến vị trí trên đĩa.

- **Minh họa:**
  - Đầu đọc/ghi bắt đầu từ khối 98.
  - Sau đó, xử lý các khối lần lượt theo thứ tự: 183, 37, 122, 14, 124, 65, 67.

#### First-Come, First-Served (FCFS)

- Đầu đọc: |---98---|---183---|---37---|---122---|---14---|---124---|---65---|---67---|

### 2. **Shortest Seek Time First (SSTF)**:

- **Cách thức hoạt động:** Chọn yêu cầu có thời gian đợi (seek time) ngắn nhất từ vị trí hiện tại của đầu đọc/ghi.

- **Mô tả chi tiết:**

  - Bắt đầu từ vị trí hiện tại của đầu đọc/ghi.
  - Chọn yêu cầu gần nhất (có seek time ngắn nhất) để xử lý tiếp theo.
  - Tiếp tục chọn yêu cầu gần nhất cho đến khi không còn yêu cầu nào nữa.

- **Minh họa:**
  - Bắt đầu từ khối 98.
  - Tiếp theo là khối 122 (vì 122 có seek time ngắn nhất so với 98 và 183).
  - Sau đó là khối 65 (vì 65 có seek time ngắn nhất so với 37, 14 và 124).
  - Tiếp tục chọn các khối tiếp theo dựa trên seek time ngắn nhất.

#### Shortest Seek Time First (SSTF)

- Đầu đọc: |---98---|---122---|---65---|---67---|---37---|---14---|---124---|---183---|

### 3. **SCAN (Elevator)**:

- **Cách thức hoạt động:** Đầu đọc/ghi di chuyển từ một đầu của đĩa đến đầu còn lại, và xử lý yêu cầu trên đường đi. Khi đến cuối đĩa, đầu đọc/ghi quay ngược lại.

- **Mô tả chi tiết:**

  - Bắt đầu từ vị trí hiện tại của đầu đọc/ghi.
  - Di chuyển đến đầu đĩa kế tiếp và xử lý các yêu cầu theo hướng đó.
  - Khi đến cuối đĩa, quay ngược lại và xử lý các yêu cầu trên đường đi.

- **Minh họa:**
  - Bắt đầu từ khối 98 và đi đến cuối đĩa (khối 183).
  - Quay ngược lại và xử lý các khối trên đường đi (khối 122, 14, 65, 67).

#### SCAN (Elevator)

- Đầu đọc: |---98---|---122---|---124---|---14---|---65---|---67---|---183---|

### 4. **C-SCAN (Circular SCAN)**:

- **Cách thức hoạt động:** Giống như SCAN, nhưng chỉ quét một chiều và quay vòng tròn khi đến cuối đĩa để xử lý yêu cầu.

- **Mô tả chi tiết:**

  - Giống như SCAN, nhưng không quay lại khi đến cuối đĩa.
  - Khi đến cuối đĩa, quay vòng tròn và đi tiếp từ đầu đĩa đến vị trí ban đầu.

- **Minh họa:**
  - Bắt đầu từ khối 98 và đi đến cuối đĩa (khối 183).
  - Quay vòng tròn và xử lý các khối còn lại trên đường đi (khối 122, 14, 124, 65, 67).

#### C-SCAN (Circular SCAN)

- Đầu đọc: |---98---|---122---|---124---|---14---|---65---|---67---|---183---|---37---|

### 5. **LOOK**:

- **Cách thức hoạt động:** Tương tự như SCAN, nhưng chỉ di chuyển đến cuối đĩa nếu không còn yêu cầu nào ở hướng đó, không cần quay vòng như SCAN.

- **Mô tả chi tiết:**

  - Tương tự như SCAN, nhưng không quay lại khi đến cuối đĩa.
  - Khi đến cuối đĩa, đi ngược lại nếu có yêu cầu ở hướng ngược lại.

- **Minh họa:**
  - Bắt đầu từ khối 98 và đi đến khối 183.
  - Sau đó, quay về phía khối 37 và xử lý các khối trên đường đi (khối 37, 14, 65).
  - Tiếp tục quay lại phía khối 122 và xử lý các khối trên đường đi (khối 122, 124).
  - Cuối cùng, quay lại phía khối 67 và xử lý khối cuối cùng.

#### LOOK

- Đầu đọc: |---98---|---122---|---124---|---14---|---65---|---67---|---183---|---37---|
