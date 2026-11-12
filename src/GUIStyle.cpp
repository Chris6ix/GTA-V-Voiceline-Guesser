// Standard libraries and internal headers
#include "GUIHelpers.h" // Used for UIScale()
// External libraries and headers
#include "imgui.h" // ImGui API

// Global GUI style (Modern style by LousyBook-01 from ImThemes, modified by Chris6ix)
void LoadGUIStyle() {
	ImGuiStyle& style = ImGui::GetStyle();

	style.Alpha = 1.0f;
	style.DisabledAlpha = 0.3f;
	style.WindowPadding = UIScale(ImVec2(10.1f, 10.1f));
	style.WindowRounding = (0.0f);
	style.WindowBorderSize = UIScale(1.0f);
	style.WindowMinSize = UIScale(ImVec2(20.0f, 32.0f));
	style.WindowTitleAlign = UIScale(ImVec2(0.5f, 0.5f));
	style.WindowMenuButtonPosition = ImGuiDir_Right;
	style.ChildRounding = UIScale(8.2f);
	style.ChildBorderSize = UIScale(1.0f);
	style.PopupRounding = UIScale(10.7f);
	style.PopupBorderSize = UIScale(1.0f);
	style.FramePadding = UIScale(ImVec2(3.0f, 1.5f));
	style.FrameRounding = UIScale(4.8f);
	style.FrameBorderSize = UIScale(0.0f);
	style.ItemSpacing = UIScale(ImVec2(9.7f, 5.3f));
	style.ItemInnerSpacing = UIScale(ImVec2(5.4f, 9.3f));
	style.CellPadding = UIScale(ImVec2(7.9f, 2.0f));
	style.IndentSpacing = UIScale(10.7f);
	style.ColumnsMinSpacing = UIScale(6.0f);
	style.ScrollbarSize = UIScale(12.1f);
	style.ScrollbarRounding = UIScale(20.0f);
	style.GrabMinSize = UIScale(10.0f);
	style.GrabRounding = UIScale(4.6f);
	style.TabRounding = UIScale(4.0f);
	style.TabBorderSize = UIScale(0.0f);
	style.ColorButtonPosition = ImGuiDir_Right;
	style.ButtonTextAlign = UIScale(ImVec2(0.5f, 0.5f));
	style.SelectableTextAlign = UIScale(ImVec2(0.0f, 0.0f));
	
	style.Colors[ImGuiCol_Text] = ImVec4(255/255.0f, 255/255.0f, 255/255.0f, 1.0f);
	style.Colors[ImGuiCol_TextDisabled] = ImVec4(255/255.0f, 255/255.0f, 255/255.0f, 0.4f);
	style.Colors[ImGuiCol_WindowBg] = ImVec4(10/255.0f, 10/255.0f, 10/255.0f, 0.94f);
	style.Colors[ImGuiCol_ChildBg] = ImVec4(0/255.0f, 0/255.0f, 0/255.0f, 0.0f);
	style.Colors[ImGuiCol_PopupBg] = ImVec4(13/255.0f, 13/255.0f, 13/255.0f, 0.94f);
	style.Colors[ImGuiCol_Border] = ImVec4(109/255.0f, 109/255.0f, 127/255.0f, 0.5f);
	style.Colors[ImGuiCol_BorderShadow] = ImVec4(0/255.0f, 0/255.0f, 0/255.0f, 0.0f);
	style.Colors[ImGuiCol_FrameBg] = ImVec4(0/255.0f, 0/255.0f, 0/255.0f, 0.7f); // FrameBg controls slider box, checkbox, input boxes etc
	style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(3/255.0f, 3/255.0f, 3/255.0f, 0.6f);
	style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0/255.0f, 0/255.0f, 0/255.0f, 0.7f);
	style.Colors[ImGuiCol_TitleBg] = ImVec4(0/255.0f, 0/255.0f, 0/255.0f, 1.0f);
	style.Colors[ImGuiCol_TitleBgActive] = ImVec4(24/255.0f, 24/255.0f, 24/255.0f, 1.0f);
	style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0/255.0f, 0/255.0f, 0/255.0f, 0.29f);
	style.Colors[ImGuiCol_MenuBarBg] = ImVec4(35/255.0f, 35/255.0f, 35/255.0f, 1.0f);
	style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0/255.0f, 0/255.0f, 0/255.0f, 0.70f);
	style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(5/255.0f, 5/255.0f, 5/255.0f, 1.0f);
	style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(25/255.0f, 25/255.0f, 25/255.0f, 1.0f);
	style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(255/255.0f, 59/255.0f, 59/255.0f, 1.0f);
	style.Colors[ImGuiCol_CheckMark] = ImVec4(250/255.0f, 66/255.0f, 66/255.0f, 1.0f);
	style.Colors[ImGuiCol_CheckboxSelectedBg] = ImVec4(0/255.0f, 0/255.0f, 0/255.0f, 0.7f);
	style.Colors[ImGuiCol_SliderGrab] = ImVec4(255/255.0f, 59/255.0f, 59/255.0f, 1.0f);
	style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(255/255.0f, 59/255.0f, 59/255.0f, 1.0f);
	style.Colors[ImGuiCol_Button] = ImVec4(0/255.0f, 0/255.0f, 0/255.0f, 0.70f);
	style.Colors[ImGuiCol_ButtonHovered] = ImVec4(25/255.0f, 25/255.0f, 25/255.0f, 0.7f);
	style.Colors[ImGuiCol_ButtonActive] = ImVec4(255/255.0f, 59/255.0f, 59/255.0f, 1.0f);
	style.Colors[ImGuiCol_Header] = ImVec4(0/255.0f, 0/255.0f, 0/255.0f, 0.4549356f);
	style.Colors[ImGuiCol_HeaderHovered] = ImVec4(46/255.0f, 46/255.0f, 46/255.0f, 0.8f);
	style.Colors[ImGuiCol_HeaderActive] = ImVec4(249/255.0f, 66/255.0f, 66/255.0f, 1.0f);
	style.Colors[ImGuiCol_Separator] = ImVec4(0/255.0f, 0/255.0f, 0/255.0f, 0.5f);
	style.Colors[ImGuiCol_SeparatorHovered] = ImVec4(25/255.0f, 102/255.0f, 191/255.0f, 0.78f);
	style.Colors[ImGuiCol_SeparatorActive] = ImVec4(25/255.0f, 102/255.0f, 191/255.0f, 1.0f);
	style.Colors[ImGuiCol_ResizeGrip] = ImVec4(66/255.0f, 150/255.0f, 249/255.0f, 0.2f);
	style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(66/255.0f, 150/255.0f, 249/255.0f, 0.67f);
	style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(66/255.0f, 150/255.0f, 249/255.0f, 0.95f);
	style.Colors[ImGuiCol_Tab] = ImVec4(27/255.0f, 27/255.0f, 27/255.0f, 1.0f);
	style.Colors[ImGuiCol_TabHovered] = ImVec4(255/255.0f, 93/255.0f, 172/255.0f, 0.8f);
	style.Colors[ImGuiCol_TabActive] = ImVec4(255/255.0f, 57/255.0f, 57/255.0f, 1.0f);
	style.Colors[ImGuiCol_TabUnfocused] = ImVec4(28/255.0f, 43/255.0f, 61/255.0f, 0.97f);
	style.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(34/255.0f, 66/255.0f, 108/255.0f, 1.0f);
	style.Colors[ImGuiCol_PlotLines] = ImVec4(255/255.0f, 255/255.0f, 255/255.0f, 1.0f);
	style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(255/255.0f, 109/255.0f, 89/255.0f, 1.0f);
	style.Colors[ImGuiCol_PlotHistogram] = ImVec4(255/255.0f, 55/255.0f, 55/255.0f, 1.0f);
	style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(255/255.0f, 55/255.0f, 178/255.0f, 1.0f);
	style.Colors[ImGuiCol_TableHeaderBg] = ImVec4(255/255.0f, 60/255.0f, 60/255.0f, 1.0f);
	style.Colors[ImGuiCol_TableBorderStrong] = ImVec4(255/255.0f, 81/255.0f, 81/255.0f, 1.0f);
	style.Colors[ImGuiCol_TableBorderLight] = ImVec4(255/255.0f, 144/255.0f, 144/255.0f, 0.37f);
	style.Colors[ImGuiCol_TableRowBg] = ImVec4(185/255.0f, 86/255.0f, 255/255.0f, 0.0f);
	style.Colors[ImGuiCol_TableRowBgAlt] = ImVec4(255/255.0f, 70/255.0f, 70/255.0f, 0.11f);
	style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(249/255.0f, 66/255.0f, 66/255.0f, 1.0f);
	style.Colors[ImGuiCol_DragDropTarget] = ImVec4(255/255.0f, 255/255.0f, 0/255.0f, 0.9f);
	style.Colors[ImGuiCol_NavHighlight] = ImVec4(0/255.0f, 0/255.0f, 0/255.0f, 0.64f);
	style.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(255/255.0f, 255/255.0f, 255/255.0f, 0.47f);
	style.Colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0/255.0f, 0/255.0f, 0/255.0f, 0.74f);
	style.Colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0/255.0f, 0/255.0f, 0/255.0f, 0.80f);
}