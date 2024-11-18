#include "GraphicEditor.h"

GraphicEditor::~GraphicEditor() {
    for (Shape* shape : shapes) {
        delete shape;
    }
}

void GraphicEditor::insertShape() {
    int choice;
    cout << "��:1, ��:2, �簢��:3 >> ";
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
        cout << "�߸��� �Է��Դϴ�." << endl;
        return;
    }
    shapes.push_back(shape);
}

void GraphicEditor::deleteShape() {
    int index;
    cout << "�����ϰ��� �ϴ� ������ �ε��� >> ";
    cin >> index;

    if (index < 0 || index >= shapes.size()) {
        cout << "�߸��� �ε����Դϴ�." << endl;
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
    cout << "�׷��� �������Դϴ�." << endl;
    while (true) {
        cout << "����:1, ����:2, ��κ���:3, ����:4 >> ";
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
            cout << "�߸��� �Է��Դϴ�." << endl;
        }
    }
}
