#include "GraphicEditor.h"

GraphicEditor::~GraphicEditor() {
    for (Shape* shape : shapes) {
        delete shape;
    }
}

void GraphicEditor::insertShape() {
    int choice;
    cout << "선:1, 원:2, 사각형:3 >> ";
    cin >> choice;
    Shape* shape = nullptr;

    switch (choice) {
    case 1:
        shape = new Line();
        break;
    case 2:
        shape = new Circle();
        break;
    case 3:
        shape = new Rectangle();
        break;
    default:
        cout << "잘못된 입력입니다." << endl;
        return;
    }
    shapes.push_back(shape);
}

void GraphicEditor::deleteShape() {
    int index;
    cout << "삭제하고자 하는 도형의 인덱스 >> ";
    cin >> index;

    if (index < 0 || index >= shapes.size()) {
        cout << "잘못된 인덱스입니다." << endl;
        return;
    }
    delete shapes[index];
    shapes.erase(shapes.begin() + index);
}

void GraphicEditor::showShapes() const {
    for (int i = 0; i < shapes.size(); i++) {
        cout << i << ": ";
        shapes[i]->draw();
    }
}

void GraphicEditor::run() {
    int choice;
    cout << "그래픽 에디터입니다." << endl;
    while (true) {
        cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
        cin >> choice;

        switch (choice) {
        case 1:
            insertShape();
            break;
        case 2:
            deleteShape();
            break;
        case 3:
            showShapes();
            break;
        case 4:
            cout << " " << endl;
            return;
        default:
            cout << "잘못된 입력입니다." << endl;
        }
    }
}
