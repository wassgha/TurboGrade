/********************************************************************************
** Form generated from reading UI file 'preferences.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREFERENCES_H
#define UI_PREFERENCES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Preferences
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *logo;
    QSpacerItem *horizontalSpacer;
    QLabel *logo_img;
    QSpacerItem *horizontalSpacer_2;
    QLabel *name;
    QLabel *version;
    QSpacerItem *verticalSpacer;
    QGroupBox *sync_settings;
    QFormLayout *formLayout_2;
    QLabel *repo_url_label;
    QLineEdit *repo_url;
    QLabel *repo_pwd_label;
    QLineEdit *repo_pwd;
    QGroupBox *software_preferences;
    QFormLayout *formLayout_3;
    QLabel *theme_label;
    QComboBox *theme;
    QLabel *font_size_label;
    QSpinBox *font_size;
    QLabel *label;
    QPushButton *save_btn;

    void setupUi(QDialog *Preferences)
    {
        if (Preferences->objectName().isEmpty())
            Preferences->setObjectName(QStringLiteral("Preferences"));
        Preferences->setWindowModality(Qt::WindowModal);
        Preferences->resize(400, 438);
        Preferences->setStyleSheet(QLatin1String("QDialog {\n"
"	background: white;\n"
"}\n"
"\n"
"#save_btn {\n"
"	border:none;\n"
"	text-transform: uppercase;\n"
"	padding: 10px;\n"
"	padding-left: 15px;\n"
"	padding-right: 15px;\n"
"	border-radius: 18px;\n"
"	color: white;\n"
"	background: #63c46b;\n"
"	width: 100px;\n"
"	height: 18px;\n"
"\n"
"}\n"
""));
        Preferences->setModal(true);
        verticalLayout = new QVBoxLayout(Preferences);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        logo = new QHBoxLayout();
        logo->setObjectName(QStringLiteral("logo"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        logo->addItem(horizontalSpacer);

        logo_img = new QLabel(Preferences);
        logo_img->setObjectName(QStringLiteral("logo_img"));
        logo_img->setMinimumSize(QSize(100, 100));
        logo_img->setMaximumSize(QSize(100, 100));
        logo_img->setPixmap(QPixmap(QString::fromUtf8(":/logo/res/icon.png")));
        logo_img->setScaledContents(true);
        logo_img->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        logo->addWidget(logo_img);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        logo->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(logo);

        name = new QLabel(Preferences);
        name->setObjectName(QStringLiteral("name"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(name->sizePolicy().hasHeightForWidth());
        name->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        name->setFont(font);
        name->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(name);

        version = new QLabel(Preferences);
        version->setObjectName(QStringLiteral("version"));
        version->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(version);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        sync_settings = new QGroupBox(Preferences);
        sync_settings->setObjectName(QStringLiteral("sync_settings"));
        formLayout_2 = new QFormLayout(sync_settings);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        repo_url_label = new QLabel(sync_settings);
        repo_url_label->setObjectName(QStringLiteral("repo_url_label"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, repo_url_label);

        repo_url = new QLineEdit(sync_settings);
        repo_url->setObjectName(QStringLiteral("repo_url"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(repo_url->sizePolicy().hasHeightForWidth());
        repo_url->setSizePolicy(sizePolicy1);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, repo_url);

        repo_pwd_label = new QLabel(sync_settings);
        repo_pwd_label->setObjectName(QStringLiteral("repo_pwd_label"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, repo_pwd_label);

        repo_pwd = new QLineEdit(sync_settings);
        repo_pwd->setObjectName(QStringLiteral("repo_pwd"));
        repo_pwd->setInputMethodHints(Qt::ImhSensitiveData);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, repo_pwd);


        verticalLayout->addWidget(sync_settings);

        software_preferences = new QGroupBox(Preferences);
        software_preferences->setObjectName(QStringLiteral("software_preferences"));
        formLayout_3 = new QFormLayout(software_preferences);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        theme_label = new QLabel(software_preferences);
        theme_label->setObjectName(QStringLiteral("theme_label"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, theme_label);

        theme = new QComboBox(software_preferences);
        theme->setObjectName(QStringLiteral("theme"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, theme);

        font_size_label = new QLabel(software_preferences);
        font_size_label->setObjectName(QStringLiteral("font_size_label"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, font_size_label);

        font_size = new QSpinBox(software_preferences);
        font_size->setObjectName(QStringLiteral("font_size"));
        font_size->setInputMethodHints(Qt::ImhDigitsOnly);
        font_size->setMaximum(30);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, font_size);


        verticalLayout->addWidget(software_preferences);

        label = new QLabel(Preferences);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        save_btn = new QPushButton(Preferences);
        save_btn->setObjectName(QStringLiteral("save_btn"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/misc/res/confirm.png"), QSize(), QIcon::Normal, QIcon::Off);
        save_btn->setIcon(icon);

        verticalLayout->addWidget(save_btn);


        retranslateUi(Preferences);

        QMetaObject::connectSlotsByName(Preferences);
    } // setupUi

    void retranslateUi(QDialog *Preferences)
    {
        Preferences->setWindowTitle(QApplication::translate("Preferences", "Form", Q_NULLPTR));
        logo_img->setText(QString());
        name->setText(QApplication::translate("Preferences", "TurboGrade\342\204\242", Q_NULLPTR));
        version->setText(QApplication::translate("Preferences", "v1.0.2", Q_NULLPTR));
        sync_settings->setTitle(QApplication::translate("Preferences", "Synchronization Settings", Q_NULLPTR));
        repo_url_label->setText(QApplication::translate("Preferences", "Git Repo URL :", Q_NULLPTR));
        repo_url->setPlaceholderText(QApplication::translate("Preferences", "ssh://user:password@ip_addr/home/folder", Q_NULLPTR));
        repo_pwd_label->setText(QApplication::translate("Preferences", "Git Password :", Q_NULLPTR));
        repo_pwd->setPlaceholderText(QApplication::translate("Preferences", "Password", Q_NULLPTR));
        software_preferences->setTitle(QApplication::translate("Preferences", "Software preferences", Q_NULLPTR));
        theme_label->setText(QApplication::translate("Preferences", "Code Editor Theme :", Q_NULLPTR));
        theme->clear();
        theme->insertItems(0, QStringList()
         << QApplication::translate("Preferences", "Dark Theme", Q_NULLPTR)
         << QApplication::translate("Preferences", "Light Theme", Q_NULLPTR)
        );
        font_size_label->setText(QApplication::translate("Preferences", "Code Editor Text Size :", Q_NULLPTR));
        label->setText(QApplication::translate("Preferences", "Please restart the software to see the changes", Q_NULLPTR));
        save_btn->setText(QApplication::translate("Preferences", "Save settings", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Preferences: public Ui_Preferences {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREFERENCES_H
