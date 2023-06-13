## 1. Tuần 1

1. Viết chương trình nhập vào một phân số, rút gọn phân số và xuất kết quả.
2. Viết chương trình nhập vào hai phân số, tìm phân số lớn nhất và xuất kết quả.
3. Viết chương trình nhập vào hai phân số. Tính tổng, hiệu, tích, thương giữa chúng
và xuất kết quả.
4. Viết chương trình nhập vào một ngày. Tìm ngày kế tiếp và xuất kết quả.
5. Viết chương trình nhập họ tên, điểm toán, điểm văn của một học sinh. Tính điểm
trung bình và xuất kết quả.


## 2. Tuần 2
1. Thiết lập lớp PhanSo để biểu diễn khái niệm phân số với hai thành phần dữ liệu
tử số, mẫu số và các hàm thành phần cộng, trừ, nhân, chia hai phân số, các
hàm thành phần xuất, nhập, định giá trị cho phân số. Viết chương trình cho
phép nhập vào hai phân số, in ra kết quả các phép toán cộng, trừ, nhân, chia hai
phân số kể trên.
2. Xây dựng lớp biểu diễn khái niệm số phức với hai thành phần dữ liệu thực, ảo
và các hàm thành phần xuất, nhập, định giá trị cho số phức, cộng, trừ, nhân,
chia hai số phức. Viết chương trình cho phép nhập vào hai số phức, in ra kết quả
các phép toán cộng, trừ, nhân, chia hai số phức kể trên.
Ví dụ: Cho hai số phức A(a1, a2), B(b1, b2)
    * A + B = (a1+b1, a2+b2); 
    * A - B = (a1-b1, a2-b2); 
    * A * B = (a1*b1 – a2*b2, a1*b2+a2*b1); 
    * A / B = [(a1*b1 + a2*b2)/(b1^2 + b2^2) , (b1*a2 - a1*b2)/(b1^2 + b2^2)];
3. Xây dựng lớp Candidate (Thí sinh) gồm các thuộc tính: mã, tên, ngày tháng năm
sinh, điểm thi Toán, Văn, Anh và các phương thức cần thiết.
Xây dựng lớp TestCandidate để kiểm tra lớp trên:
- Nhập vào n thí sinh (n do người dùng nhập)
- In ra thông tin về các thí sinh có tổng điểm lớn hơn 15


## 3. Tuần 3
1. Định nghĩa lớp Diem biểu diễn khái niệm điểm trong mặt phẳng với hai thành
phần dữ liệu hoành độ và tung độ. Viết các phương thức thiết lập, các hàm thành
phần cho phép thay đổi nội dung của điểm, lấy hoành độ, tung độ, tịnh tiến, nhập,
xuất một điểm.
2. Viết định nghĩa lớp TamGiac để biểu diễn khái niệm tam giác trong mặt phẳng
với các phương thức thiết lập, huỷ bỏ (nếu có). Các hàm thành phần nhập, xuất,
tịnh tiến, quay, phóng to, thu nhỏ tam giác.
3. Viết định nghĩa lớp DaGiac để biểu diễn khái niệm đa giác trong mặt phẳng với
các hàm thành phần tương tự như lớp TamGiac.


## 4. Tuần 4
1. Định nghĩa lớp dữ liệu CTimeSpan để biểu diễn khái niệm khoảng thời gian, các
hàm thành phần và các phép toán cần thiết (+, -, ==, !=, >, >=, <, <=), hàm xuất,
nhập. Lưu ý viết theo dạng hàm: cong, tru, ...; không dùng overloading operator
2. Định nghĩa lớp CTime biểu diễn khái niệm thời điểm có các thành phần giờ phút
giây. Định nghĩa các phép toán +,-(cộng, trừ thêm một số nguyên giây), - (phép
trừ hai CTime để được một CTimSpan), ++, -- (thêm bớt một giây) , hàm xuất,
nhập. Lưu ý viết theo dạng hàm: cong, tru, ...; không dùng overloading operator
3. Định nghĩa lớp CDate biểu diễn khái niệm ngày, tháng, năm với các phép toán +,- (cộng, trừ thêm một số ngày), ++, -- (thêm bớt một ngày), - (khoảng cách giữa
hai CDate tính bằng ngày), hàm xuất, nhập. Lưu ý viết theo dạng hàm: cong, tru,
...; không dùng overloading operator
4. Định nghĩa lớp biểu diễn khái niệm đa thức có bậc bất kỳ với các hàm thành
phần và phép toán cần thiết.


## 5.Tuần 5
1. Viết định nghĩa lớp String để biểu diễn khái niệm chuỗi ký tự với các phương
thức thiết lập và huỷ bỏ, các hàm thành phần tính chiều dài chuỗi, nối hai chuỗi,
đảo chuỗi, nhập và xuất chuỗi.
2. Áp dụng các lớp string và vector trong thư viện STL để xây dựng chương trình thống kê
đoạn văn như sau:
- Đọc một đoạn văn từ file văn bản.
- Đếm số lượng câu trong đoạn văn (câu kết thúc thúc bởi dấu ., !, ?).
- Đếm số lượng từ trong mỗi câu (từ tách biệt so với các từ khác bởi khoảng trắng).
- Tìm từ xuất hiện nhiều nhất trong đoạn văn (có thể có nhiều từ).
- Sắp xếp tăng dần các từ (theo thứ tự từ điển) trong mỗi câu.
- Kết xuất kết quả ra file văn bản theo cấu trúc sau:
• Dòng đầu tiên chứa C là số lượng câu.
• C dòng tiếp theo chứa Ti là số lượng từ trong câu thứ i (1 <= i <= C).
• Dòng kế tiếp chứa các từ xuất hiện nhiều nhất.
• Các dòng kế tiếp chứa đoạn văn sau khi đã sắp xếp.

## 6.Tuần 6
1. Làm lại bài số phức với một phương thức thiết lập duy nhất cho phép quan điểm
một số thực như một số phức đặc biệt (phần ảo bằng 0). Định nghĩa các phép
toán +, -, *, /, = =, !=, >, >=, <, <= trên số phức. Định nghĩa phép toán << và >>
để xuất và nhập dữ liệu vào số phức.
2. Làm lại bài phân số với các phương thức thiết lập cho phép sử dụng một số
nguyên như một phân số đặc biệt (mẫu số bằng 1). Định nghĩa các phép toán +, -,
*, /, = =, != , >, >=, <, <= trên phân số. Định nghĩa phép toán << và >> để xuất
và nhập dữ liệu vào phân số.
3. Định nghĩa lớp dữ liệu CTimeSpan để biểu diễn khái niệm khoảng thời gian, các
hàm thành phần và các phép toán cần thiết (+, -, ==, !=, >, >=, <, <=).
4. Định nghĩa lớp CTime biểu diễn khái niệm thời điểm có các thành phần giờ phút
giây. Định nghĩa các phép toán +, - (cộng, trừ thêm một số nguyên giây), - (phép
trừ hai CTime để được một CTimSpan), ++, -- (thêm bớt một giây). Phép toán
<<, >> để xuất, nhập dữ liệu loại CTime.
5. Định nghĩa lớp CDate biểu diễn khái niệm ngày, tháng, năm với các phép toán +,
- (cộng, trừ thêm một số ngày), ++, -- (thêm bớt một ngày), - (khoảng cách giữa
hai CDate tính bằng ngày). Phép toán <<, >> để xuất, nhập dữ liệu loại CDate.
6. Hãy định nghĩa lớp CString biểu diễn khái niệm chuỗi ký tự với các phương thức
thiết lập, huỷ bỏ, các hàm thành phần và các phép toán cần thiết (+, gán, so sánh
hai chuỗi).
7. Định nghĩa lớp biểu diễn khái niệm đa thức có bậc bất kỳ với các hàm thành
phần và phép toán cần thiết.
8. Định nghĩa lớp CVector biểu diễn khái niệm vector trong không gian có số chiều
bất kỳ với các hàm thành phần và các phép toán cần thiết.
   Định nghĩa lớp CMatrix biểu diễn khái niệm ma trận có kích thước bất kỳ với các
hàm thành phần và các phép toán cần thiết.
Viết hàm tính tích của một ma trận và một vector. Tích của hai ma trận.
9. Hãy định nghĩa lớp INTEGER có thể hoạt động như để mỗi INTEGER giống hệt
như một 'int' của ngôn ngữ C/C++.
10.Hãy định nghĩa lớp MYINT có hoạt động như kiểu dữ liệu 'int' nhưng phép cộng
hai MYINT hoạt động như phép trừ hai int và ngược lại.
11. Cho đoạn chương trình sau:
#include <iostream.h>
main(){
cout << "Hello, world.\n";
}
Hãy sửa lại chương trình trên, nhưng không sửa chữa gì hàm main, để chương
trình có thể tạo ra kết xuất:
Entering the Hello program saying...
Hello, world.
Then exiting...

## 7.Tuần 7
1. Giả sử Công ty có hai loại nhân viên: Nhân viên văn phòng và Nhân viên sản
xuất. Viết chương trình quản lý và tính lương cho từng nhân viên của công ty:
Mỗi nhân viên cần quản lý các thông tin sau: Họ tên, ngày sinh, lương
Công ty cần tính lương cho nhân viên như sau:
- Đối với nhân viên sản xuất:
▪ Lương=lương căn bản + số sản phẩm * 5.000
- Đối nhân viên văn phòng:
▪ lương = số ngày làm việc * 100.000
2. Xây dựng các loại đối tượng sinh viên, học sinh, công nhân, nghệ sĩ, ca sĩ gồm
các thông tin cơ bản như họ tên, ngày tháng năm sinh, nơi ở, giới tính. Sinh viên
thì xác định thêm là sinh viên năm thứ mấy, niên khoá, học trường nào, ngành
học. Học sinh thì xác định thêm trường học và lớp. Công nhân có nơi làm việc và
lương. Nghệ sĩ, ca sĩ có nghệ danh và lĩnh vực chuyên môn. Viết chương trình
cho phép nhập vào một trong các loại đối tượng kể trên. In thông tin đối tượng
đó.
3. Tạo một danh sách các đối tượng, mỗi đối tượng thuộc một trong các loại: sinh
viên, học sinh, công nhân, nghệ sĩ, ca sĩ. Viết chương trình cho phép nhập danh
sách kể trên, in thông tin của từng đối tượng trong danh sách.
4. Xây dựng lớp biểu diễn khái niệm hình ellipse và hình tròn. Viết chương trình
cho phép nhập vào danh sách các hình tròn và ellipse.
5. Xây dựng các loại đối tượng hình thang, hình bình hành, hình chữ nhật, hình
vuông. Chỉ xét các hình thang, hình bình hành có đáy song song với trục hoành,
chỉ xét hình chữ nhật và hình vuông có cạnh song song với trục toạ độ. Viếtchương trình cho phép nhập vào một trong các hình kể trên. Xuất thông tin hình
đã nhập.
6. Một nông trại chăn nuôi có 3 loại gia súc: bò, cừu, và dê. Mỗi loại gia súc đều
có thể sinh con, cho sữa và phát ra tiếng kêu riêng của chúng. Khi đói, các gia
súc sẽ phát ra tiếng kêu để đòi ăn. Sau một thời gian chăn nuôi, người chủ nông
trại muốn thống kê xem trong nông trại có bao nhiêu gia súc ở mỗi loại, tổng số
lit sữa mà tất cả các gia súc của ông đã cho.
Áp dụng kế thừa, xây dựng chương trình cho phép người chủ nông trại nhập vào
số lượng gia súc ban đầu ở mỗi loại.
a. Một hôm người chủ nông trại đi vắng, tất cả gia súc trong nông trại đều
đói. Hãy cho biết những tiếng kêu nghe được trong nông trại (xuất tiếng kêu
dạng chuỗi).
b. Chương trình sẽ đưa ra thống kê các thông tin người chủ mong muốn
(nêu trên) sau một lứa sinh và một lược cho sữa của tất cả gia súc. Biết rằng:
- Tất cả gia súc ở mỗi loại đều sinh con.
- Số lượng sinh của mỗi gia súc là ngẫu nhiên.
- Tất cả gia súc ở mỗi loại đều cho sữa.
- Số lit sữa mỗi gia súc cho là ngẫu nhiên nhưng trong giới hạn sau:
• Bò: 0 – 20 lít.
• Cừu: 0 – 5 lít.
• Dê: 0 – 10 lít


## 8.Tuần 8
1. Xây dựng các loại đối tượng sách, sách giáo khoa, tiểu thuyết, tạp chí. Viết
chương trình cho phép quản lý một danh sách các loại đối tượng kể trên.
2. Xây dựng lớp DaGiac thể hiện khái niệm đa giác với các thao tác cần thiết
(nhập, xuất, tịnh tiến). Dùng kế thừa xây dựng các lớp tứ giác, tam giác. Viết
chương trình cho phép nhập vào một tam giác hoặc tứ giác. Xuất và thực hiện
các thao tác tịnh tiến hình đã nhập.
3. Thêm vào bài 2 các hình hình bình hành, hình chữ nhật và hình vuông. Định
nghĩa lại các thao tác ở lớp con nếu cần. Xuất và thực hiện thao tác tịnh tiến
hình đã nhập.
4. Viết chương trình cho phép nhập vào một trong các hình (tam giác, tứ giác,
hình bình hành, hình chữ nhật, hình vuông) kể trên, xuất và thực hiện phép
tịnh tiến cho các hình đã nhập.
5. Áp dụng liên kết động để làm lại bài tập tuần 7 (bài nông trại). Hãy so sánh
giữa 2 cách làm (không dùng liên kết động và có dùng liên kết động) và rút
ra ưu điểm của cách dùng liên kết động


## 9.Tuần 9 
1. Áp dụng function template để giải các bài tập sau:
   * Tìm min, max giữa 2 phần tử kiểu T (int, float, PhanSo, …).
   * Tìm phần tử dương lớn nhất trong mảng kiểu T (int, float, PhanSo, …).
   * Sắp xếp tăng dần mảng kiểu T (int, float, PhanSo, ...).
2. Có 4 yêu cầu sắp xếp trên một dãy số nguyên như sau:
   * Sắp xếp dãy số nguyên theo thứ tự tăng dần.
   * Sắp xếp dãy số nguyên theo thứ tự giảm dần của gi trị tuyệt đối.
   * Sắp xếp các số nguyên chẳn tăng dần và các số nguyên lẻ giảm dần.
   * Sắp xếp các số nguyên âm giảm dần, các số nguyên dương tăng dần,
   và các số dương âm xếp trước các số nguyên dương.
Yêu cầu:
a. Bạn hãy thiết kế và cài đặt 4 thuật toán sắp xếp trên theo phương pháp
lập trình hướng đối tượng để tận dụng tối đa mã nguồn.
b. Nếu phải thay đổi kiểu dữ liệu, bạn hãy tổng quát hóa các thuật toán
sắp xếp trên để có thể sắp xếp các dãy số có kiểu dữ liệu bất kì. (sử dụng
template)
3. Công ty XYZ quản lý việc mua hàng của 3 loại khách hàng:
- Loại A: Khách hàng bình thường (gồm x khách hàng):
Số tiền khách hàng trả = Số lượng hàng * đơn giá hàng + Thuế VAT (10%)
- Loại B: Khách hàng thân thiết (gồm y khách hàng):
Phần trăm khuyến mãi = MAX (Số năm thân thiết * 5%, 50%)
Số tiền khách hàng trả = (Số lượng hàng * đơn giá hàng) * (100% - Phần trăm
khuyến mãi) + Thuế VAT (10%)
- Loại C: Khách hàng đặc biệt (gồm z khách hàng):
Số tiền khách hàng trả = (Số lượng hàng * đơn giá hàng) *50% + Thuế VAT
(10%)
Viết chương trình thực hiện các yêu cầu sau:Trường ĐH Công Nghệ Thông Tin – Khoa Công Nghệ Phần Mềm
   * Nhập danh sách khách hàng từ file văn bản XYZ.INP. 0< x,y,z<1000.
   * Sử dụng con trỏ hàm để tính Tổng số tiền mỗi khách hàng trong danh sách
phải trả. Xuất kết quả ra file XYZ.OUT dưới định dạng theo quy định.
   * Thiết kế và xây dựng các lớp để giải quyết bài toán tính Tổng số tiền công
ty thu được. Xuất kết quả ra file XYZ.OUT dưới định dạng theo quy định. 

4. Khách sạn SOFITEL có 3 loại phòng với doanh thu phòng của tháng được tính
như sau:
- Loại Deluxe: doanh thu phòng = (Số đêm * 750000 + Phí dịch vụ) * (100%
+ Phí phục vụ)
- Loại Premium: doanh thu phòng = (Số đêm * 500000 + Phí dịch vụ) * 105%
Thông tin của x
khách hàng Loại A
Thông tin của y
khách hàng Loại B
Thông tin của z
khách hàng Loại CTrường ĐH Công Nghệ Thông Tin – Khoa Công Nghệ Phần Mềm
- Loại Business: doanh thu phòng = Số đêm * 300000
Viết chương trình thực hiện các yêu cầu sau:
   * Nhập danh sách các phòng được sử dụng từ tập tin văn bản SOFITEL.INP.
d: số phòng loại Deluxe, p: số phòng loại Premium, b: số phịng loại Business
(0<d,p,b<1000)
   * Sử dụng con trỏ hàm để tính doanh thu từng loại phòng khách sạn thu được.
Xuất kết quả ra file SOFITEL.OUT dưới định dạng theo quy định.
   * Thiết kế và xây dựng các lớp để liệt kê phòng có doanh thu vượt trội. Biết
phòng có doanh thu vượt trội thỏa tính chất:
Doanh thu tháng >= Doanh thu tháng trước * 125%
Xuất kết quả ra file SOFITEL.OUT dưới định dạng theo quy định. [BTTuan9.pdf](https://github.com/noirh8/OOP/files/11730174/BTTuan9.pdf)

5. Cho N hình, gồm các loại hình: tam giác, chữ nhật, hình vuông, hình tròn (đọc từ
file).
Các hình được mô tả với các thông số như sau:
- Hình tam giác: ký hiệu l ‘G’ kèm theo tọa độ 3 đỉnh.
- Hình chữ nhật: ký hiệu l ‘C’ kèm theo tọa độ góc trái trên và chiều dài
(theo trục Ox) và chiều rộng (theo trục Oy).
- Hình vuông: ký hiệu l ‘V’ kèm theo tọa độ góc trái trên và chiều dài cạnh.
- Hình tròn: ký hiệu l ‘T’ kèm theo tọa độ tâm và bán kính.
Mỗi tọa độ được xác định bởi hai số nguyên.
Tìm hình chữ nhật nhỏ nhất bao quanh N hình được cho xác định bởi tọa độ góc
trái trên và chiều dài, chiều rộng của hình chữ nhật đó. Xuất kết quả ra tập tin
văn bản như ví dụ sau:
Yêu cầu: thiết kế các lớp đối tượng để giải quyết sao cho chương trình có khả
năng tiến hóa, dễ dàng thêm các loại hình mới.
6. Cho sẵn 3 hàm số:
 - f(x) = k1*x - 3Trường ĐH Công Nghệ Thông Tin – Khoa Công Nghệ Phần Mềm
 - g(x) = -3x<sup>2</sup> + k2*x
 - h(x) = 7x<sup>3</sup> + k3*x<sup>2</sup> - 5
và 3 tham số min, max, step.
Viết chương trình thực hiện các yêu cầu sau:
   - Đọc 6 tham số trên từ tập tin KHAOSAT.INP. Tập tin chỉ gồm một dòng duy
nhất chứa 6 số thực k1, k2, k3, min, max, step (mỗi số cách bởi một khoảng
trắng).
   - Sử dụng con trỏ hàm để in bảng giá trị của 3 hàm trên trong khoảng [min,
max] với bước nhảy l step ra tập tin KHAOSAT.OUT. Dòng đầu tiên chứa
các số ứng với gi trị của x khảo st: x1, x2, x3, … (mỗi số cách nhau bởi đúng
một khoảng trắng) với x1 = min, x2 = min+step, … Dòng thứ hai chứa cc gi
trị f(x1), f(x2), f(x3), … Tương tự, dòng thứ ba cho hàm g và dòng thứ tư cho
hàm h.
   - Thiết kế và xây dựng các lớp để in ra bảng giá trị đạo hàm ra tập tin
KHAOSAT.OUT. Dòng tiếp theo đầu tiên chứa các số f’(x1), f’(x2), f’(x3), …
Tương tự cho hai dòng kế tiếp ứng với g’ và h’.
7. Viết chương trình tính diện tích và chu vi các hình: Hình chữ nhật biết hai cạnh,
hình tam giác biết ba cạnh, hình tròn biết bán kính. Chương trình có giao diện
như sau:
   * Nhập kích thước các hình
   * Hiện thị diện tích và chu vi các hình đã nhập
   * Kết thúc chương trình
Lựa chọn công việc (1, 2, 3)
Khi người sử dụng chọn 1 thì hỏi người sử dụng nhập kích thước cho hình nào,
nhập xong hỏi người sử dụng có nhập tiếp không. Yêu cầu trong chương trình có
cài đặt sự đa hình liên kết động
