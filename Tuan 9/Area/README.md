1. Áp dụng function template để giải các bài tập sau:
 Tìm min, max giữa 2 phần tử kiểu T (int, float, PhanSo, …).
 Tìm phần tử dương lớn nhất trong mảng kiểu T (int, float, PhanSo, …).
 Sắp xếp tăng dần mảng kiểu T (int, float, PhanSo, ...).
2. Có 4 yêu cầu sắp xếp trên một dãy số nguyên như sau:
 Sắp xếp dãy số nguyên theo thứ tự tăng dần.
 Sắp xếp dãy số nguyên theo thứ tự giảm dần của gi trị tuyệt đối.
 Sắp xếp các số nguyên chẳn tăng dần và các số nguyên lẻ giảm dần.
 Sắp xếp các số nguyên âm giảm dần, các số nguyên dương tăng dần,
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
Viết chương trình thực hiện các yêu cầu sau:
1) Nhập danh sách khách hàng từ file văn bản XYZ.INP. 0< x,y,z<1000.
2) Sử dụng con trỏ hàm để tính Tổng số tiền mỗi khách hàng trong danh sách
phải trả. Xuất kết quả ra file XYZ.OUT dưới định dạng theo quy định.
3) Thiết kế và xây dựng các lớp để giải quyết bài toán tính Tổng số tiền công
ty thu được. Xuất kết quả ra file XYZ.OUT dưới định dạng theo quy định
4. Khách sạn SOFITEL có 3 loại phòng với doanh thu phòng của tháng được tính
như sau:
- Loại Deluxe: doanh thu phòng = (Số đêm * 750000 + Phí dịch vụ) * (100%
+ Phí phục vụ)
- Loại Premium: doanh thu phòng = (Số đêm * 500000 + Phí dịch vụ) * 105%
- Loại Business: doanh thu phòng = Số đêm * 300000
Viết chương trình thực hiện các yêu cầu sau:
1) Nhập danh sách các phòng được sử dụng từ tập tin văn bản SOFITEL.INP.
d: số phòng loại Deluxe, p: số phòng loại Premium, b: số phịng loại Business
(0<d,p,b<1000)
2) Sử dụng con trỏ hàm để tính doanh thu từng loại phòng khách sạn thu được.
Xuất kết quả ra file SOFITEL.OUT dưới định dạng theo quy định.
3) Thiết kế và xây dựng các lớp để liệt kê phòng có doanh thu vượt trội. Biết
phòng có doanh thu vượt trội thỏa tính chất:
Doanh thu tháng >= Doanh thu tháng trước * 125%
Xuất kết quả ra file SOFITEL.OUT dưới định dạng theo quy định.
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
năng tiến hóa, dễ dàng thêm các loại hình mới
6. Cho sẵn 3 hàm số:
- f(x) = k1*x - 3
- g(x) = -3x<sup>2</sup> + k2*x
- h(x) = 7x<sup>3</sup> + k3*x<sup>2</sup> - 5 và 3 tham số min, max, step.
Viết chương trình thực hiện các yêu cầu sau:
1. Đọc 6 tham số trên từ tập tin KHAOSAT.INP. Tập tin chỉ gồm một dòng duy
nhất chứa 6 số thực k1, k2, k3, min, max, step (mỗi số cách bởi một khoảng
trắng).
2. Sử dụng con trỏ hàm để in bảng giá trị của 3 hàm trên trong khoảng [min,
max] với bước nhảy l step ra tập tin KHAOSAT.OUT. Dòng đầu tiên chứa
các số ứng với gi trị của x khảo st: x1, x2, x3, … (mỗi số cách nhau bởi đúng
một khoảng trắng) với x1 = min, x2 = min+step, … Dòng thứ hai chứa cc gi
trị f(x1), f(x2), f(x3), … Tương tự, dòng thứ ba cho hàm g và dòng thứ tư cho
hàm h.
3. Thiết kế và xây dựng các lớp để in ra bảng giá trị đạo hàm ra tập tin
KHAOSAT.OUT. Dòng tiếp theo đầu tiên chứa các số f’(x1), f’(x2), f’(x3), …
Tương tự cho hai dòng kế tiếp ứng với g’ và h’.
7. Viết chương trình tính diện tích và chu vi các hình: Hình chữ nhật biết hai cạnh,
hình tam giác biết ba cạnh, hình tròn biết bán kính. Chương trình có giao diện
như sau:
1. Nhập kích thước các hình
2. Hiện thị diện tích và chu vi các hình đã nhập
3. Kết thúc chương trình
Lựa chọn công việc (1, 2, 3)
Khi người sử dụng chọn 1 thì hỏi người sử dụng nhập kích thước cho hình nào,
nhập xong hỏi người sử dụng có nhập tiếp không. Yêu cầu trong chương trình có
cài đặt sự đa hình liên kết động
