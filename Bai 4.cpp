//#include <iostream>
//#include <string>
//#include <fstream>
//#include <iomanip>
//
//using namespace std;
//
//struct SinhVien {
//    string mssv;
//    string hoTen;
//    double diem;
//};
//
//struct QuanLySinhVien {
//    SinhVien* ds = nullptr;
//    int soLuong = 0;
//    int dungLuong = 2; // Khởi tạo mảng động nhỏ, tự nhân đôi khi đầy
//};
//
//void khoiTao(QuanLySinhVien& ql) {
//    ql.ds = new SinhVien[ql.dungLuong];
//    ql.soLuong = 0;
//}
//
//void moRongBoNho(QuanLySinhVien& ql) {
//    ql.dungLuong *= 2;
//    SinhVien* dsMoi = new SinhVien[ql.dungLuong];
//    for (int i = 0; i < ql.soLuong; i++) {
//        dsMoi[i] = ql.ds[i];
//    }
//    delete[] ql.ds;
//    ql.ds = dsMoi;
//}
//
//void giaiPhong(QuanLySinhVien& ql) {
//    delete[] ql.ds;
//    ql.ds = nullptr;
//    ql.soLuong = 0;
//}
//
//// 1. THÊM SINH VIÊN (Hỗ trợ Tự động sửa nếu trùng MSSV)
//void themSinhVien(QuanLySinhVien& ql) {
//    string mssv;
//    cout << "\n--- THÊM SINH VIÊN ---\n";
//    cout << "Nhập MSSV: "; cin >> mssv;
//
//    // Kiểm tra nếu MSSV đã tồn tại thì chuyển sang chế độ SỬA
//    for (int i = 0; i < ql.soLuong; i++) {
//        if (ql.ds[i].mssv == mssv) {
//            cout << "⚠️ MSSV đã tồn tại! Chuyển sang chế độ CẬP NHẬT thông tin.\n";
//            cin.ignore();
//            cout << "Nhập Họ và Tên mới: "; getline(cin, ql.ds[i].hoTen);
//            cout << "Nhập Điểm mới: "; cin >> ql.ds[i].diem;
//            cout << "📝 Sửa thông tin sinh viên thành công!\n";
//            return;
//        }
//    }
//
//    // Nếu không trùng thì thêm mới bình thường
//    if (ql.soLuong >= ql.dungLuong) {
//        moRongBoNho(ql);
//    }
//
//    ql.ds[ql.soLuong].mssv = mssv;
//    cin.ignore();
//    cout << "Nhập Họ và Tên: "; getline(cin, ql.ds[ql.soLuong].hoTen);
//    cout << "Nhập Điểm: "; cin >> ql.ds[ql.soLuong].diem;
//
//    ql.soLuong++;
//    cout << "🎉 Thêm sinh viên thành công!\n";
//}
//
//// 2. XÓA SINH VIÊN
//void xoaSinhVien(QuanLySinhVien& ql) {
//    if (ql.soLuong == 0) {
//        cout << "❌ Danh sách trống!\n";
//        return;
//    }
//    string mssvXoa;
//    cout << "\n--- XÓA SINH VIÊN ---\n";
//    cout << "Nhập MSSV cần xóa: "; cin >> mssvXoa;
//
//    int index = -1;
//    for (int i = 0; i < ql.soLuong; i++) {
//        if (ql.ds[i].mssv == mssvXoa) {
//            index = i;
//            break;
//        }
//    }
//
//    if (index == -1) {
//        cout << "❌ Không tìm thấy sinh viên có MSSV này.\n";
//        return;
//    }
//
//    for (int i = index; i < ql.soLuong - 1; i++) {
//        ql.ds[i] = ql.ds[i + 1];
//    }
//    ql.soLuong--;
//    cout << "🗑️ Đã xóa sinh viên thành công.\n";
//}
//
//// 3. TÌM KIẾM (Linear Search)
//void timKiem(QuanLySinhVien ql) {
//    if (ql.soLuong == 0) {
//        cout << "❌ Danh sách trống!\n";
//        return;
//    }
//    string tuKhoa;
//    cout << "\n--- TÌM KIẾM SINH VIÊN ---\n";
//    cout << "Nhập MSSV hoặc Tên cần tìm: ";
//    cin.ignore();
//    getline(cin, tuKhoa);
//
//    bool timThay = false;
//    for (int i = 0; i < ql.soLuong; i++) {
//        if (ql.ds[i].mssv == tuKhoa || ql.ds[i].hoTen.find(tuKhoa) != string::npos) {
//            cout << "🔍 Tìm thấy -> MSSV: " << ql.ds[i].mssv
//                << " | Tên: " << ql.ds[i].hoTen
//                << " | Điểm: " << ql.ds[i].diem << "\n";
//            timThay = true;
//        }
//    }
//    if (!timThay) cout << "❌ Không tìm thấy sinh viên nào khớp với từ khóa.\n";
//}
//
//// 4. XẾP HẠNG LỚP (Selection Sort - Điểm giảm dần)
//void xepHangLop(QuanLySinhVien& ql) {
//    if (ql.soLuong == 0) {
//        cout << "❌ Danh sách trống!\n";
//        return;
//    }
//
//    // Thuật toán Selection Sort mẫu mực
//    for (int i = 0; i < ql.soLuong - 1; i++) {
//        int maxIdx = i;
//        for (int j = i + 1; j < ql.soLuong; j++) {
//            if (ql.ds[j].diem > ql.ds[maxIdx].diem) {
//                maxIdx = j;
//            }
//        }
//        // Hoán vị
//        SinhVien temp = ql.ds[i];
//        ql.ds[i] = ql.ds[maxIdx];
//        ql.ds[maxIdx] = temp;
//    }
//
//    cout << "\n=== BẢNG XẾP HẠNG LỚP ===\n";
//    cout << left << setw(8) << "Hạng" << setw(12) << "MSSV" << setw(25) << "Họ và Tên" << "Điểm\n";
//    for (int i = 0; i < ql.soLuong; i++) {
//        cout << left << setw(8) << i + 1
//            << setw(12) << ql.ds[i].mssv
//            << setw(25) << ql.ds[i].hoTen
//            << ql.ds[i].diem << "\n";
//    }
//}
//
//// 5. XUẤT BÁO CÁO (Thống kê + Ghi file diem_sinhvien.txt)
//void xuatBaoCao(QuanLySinhVien ql) {
//    if (ql.soLuong == 0) {
//        cout << "❌ Danh sách trống! Không có dữ liệu làm báo cáo.\n";
//        return;
//    }
//
//    double maxDiem = ql.ds[0].diem;
//    double minDiem = ql.ds[0].diem;
//    double tongDiem = 0;
//
//    for (int i = 0; i < ql.soLuong; i++) {
//        if (ql.ds[i].diem > maxDiem) maxDiem = ql.ds[i].diem;
//        if (ql.ds[i].diem < minDiem) minDiem = ql.ds[i].diem;
//        tongDiem += ql.ds[i].diem;
//    }
//    double trungBinh = tongDiem / ql.soLuong;
//
//    // Hiển thị thống kê nhanh trên màn hình
//    cout << "\n--- THỐNG KÊ NHANH ---\n";
//    cout << "Số lượng: " << ql.soLuong << " SV\n";
//    cout << "Điểm cao nhất: " << maxDiem << " | Thấp nhất: " << minDiem << "\n";
//    cout << "Trung bình lớp: " << fixed << setprecision(2) << trungBinh << "\n";
//
//    // Ghi file txt