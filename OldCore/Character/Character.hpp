#pragma once

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

#include <cstdint>
#include <string>

#define SDL_DEFAULT_SIZE 0, 0, 100, 100
#define SDL_DEFAULT_COLOR 255, 0, 0, 255

/**
 * @brief 角色基类，需要定义其他角色时，继承此类即可
 *        此处的角色指的是窗口中的任何一个元素。
 *        使用时，定义了路径的话，会自动加载材质，否则不会自动加载材质
 */

class Character {
 private:
  /**
   * @brief 角色的矩形区域和基本参数
   *        当路径为空时，使用颜色进行渲染
   *        当路径不为空时，使用材质进行渲染
   */

  SDL_Rect chara_rect{SDL_DEFAULT_SIZE};
  SDL_Color chara_color{SDL_DEFAULT_COLOR};
  SDL_Texture *chara_texture{nullptr};
  double angle{0};
  std::string path{};

  /**
   * @brief 角色的速度
   *        速度为每帧移动的像素数
   *        旋转速度为每帧旋转的角度
   */

  int32_t speed_x{0};
  int32_t speed_y{0};
  double rotate_speed{0};

 public:
  /**
   * @brief 构造函数
   *        因为角色类仅仅使用材质，不涉及材质的销毁，因此不需要在拷贝时进行深拷贝
   */

  Character() = default;
  Character(const Character &other) = default;
  Character(Character &&other) = default;
  Character &operator=(const Character &other) = default;
  Character &operator=(Character &&other) = default;

  explicit Character(const SDL_Rect &rect,
                     const SDL_Color &color = SDL_Color{SDL_DEFAULT_COLOR},
                     std::string path = "");
  virtual ~Character();

  /**
   * @brief 获得角色的内部信息，允许更改
   */

  inline SDL_Rect &get_rect() { return chara_rect; }
  inline SDL_Color &get_color() { return chara_color; }
  inline double &get_angle() { return angle; }
  inline SDL_Texture *get_texture() { return chara_texture; }
  inline std::string &get_path() { return path; }
  inline int32_t &get_speed_x() { return speed_x; }
  inline int32_t &get_speed_y() { return speed_y; }
  inline double &get_rotate_speed() { return rotate_speed; }
  inline void set_texture(SDL_Texture *texture) { chara_texture = texture; }

  void render(SDL_Renderer *renderer);

  /**
   * @brief 事件钩子，按需重写
   * 
   * @param event 事件的所有信息
   * @return true 事件向下传递
   * @return false 事件停止向下传递
   */

  virtual bool on_quit(const SDL_Event &event);
  virtual bool on_locale_changed(const SDL_Event &event);
  virtual bool on_clipboard_update(const SDL_Event &event);
  virtual bool on_sensor_update(const SDL_Event &event);

#pragma region App Events
  virtual bool on_app_terminating(const SDL_Event &event);
  virtual bool on_app_low_memory(const SDL_Event &event);
  virtual bool on_app_will_enter_background(const SDL_Event &event);
  virtual bool on_app_did_enter_background(const SDL_Event &event);
  virtual bool on_app_will_enter_foreground(const SDL_Event &event);
  virtual bool on_app_did_enter_foreground(const SDL_Event &event);
#pragma endregion

#pragma region Window Events
  virtual bool on_display_event(const SDL_Event &event);
  virtual bool on_window_event(const SDL_Event &event);
  virtual bool on_system_event(const SDL_Event &event);
#pragma endregion

#pragma region Keyboard Events
  virtual bool on_key_down(const SDL_Event &event);
  virtual bool on_key_up(const SDL_Event &event);
  virtual bool on_text_editing(const SDL_Event &event);
  virtual bool on_text_input(const SDL_Event &event);
  virtual bool on_keymap_changed(const SDL_Event &event);
#pragma endregion

#pragma region Mouse Events
  virtual bool on_mouse_down(const SDL_Event &event);
  virtual bool on_mouse_up(const SDL_Event &event);
  virtual bool on_mouse_motion(const SDL_Event &event);
  virtual bool on_mouse_wheel(const SDL_Event &event);
#pragma endregion

#pragma region Joystick Events
  virtual bool on_joystick_axis_motion(const SDL_Event &event);
  virtual bool on_joystick_ball_motion(const SDL_Event &event);
  virtual bool on_joystick_hat_motion(const SDL_Event &event);
  virtual bool on_joystick_button_down(const SDL_Event &event);
  virtual bool on_joystick_button_up(const SDL_Event &event);
  virtual bool on_joystick_device_added(const SDL_Event &event);
  virtual bool on_joystick_device_removed(const SDL_Event &event);
#pragma endregion

#pragma region Game Controller Events
  virtual bool on_controller_axis_motion(const SDL_Event &event);
  virtual bool on_controller_button_down(const SDL_Event &event);
  virtual bool on_controller_button_up(const SDL_Event &event);
  virtual bool on_controller_device_added(const SDL_Event &event);
  virtual bool on_controller_device_removed(const SDL_Event &event);
  virtual bool on_controller_device_remapped(const SDL_Event &event);
  virtual bool on_controller_touchpad_down(const SDL_Event &event);
  virtual bool on_controller_touchpad_up(const SDL_Event &event);
  virtual bool on_controller_touchpad_motion(const SDL_Event &event);
  virtual bool on_controller_sensor_update(const SDL_Event &event);
#pragma endregion

#pragma region Touch Events
  virtual bool on_touch_finger(const SDL_Event &event);
  virtual bool on_multi_gesture(const SDL_Event &event);
  virtual bool on_dollar_gesture(const SDL_Event &event);
  virtual bool on_dollar_record(const SDL_Event &event);
#pragma endregion

#pragma region Drop Events
  virtual bool on_drop_file(const SDL_Event &event);
  virtual bool on_drop_text(const SDL_Event &event);
  virtual bool on_drop_begin(const SDL_Event &event);
  virtual bool on_drop_complete(const SDL_Event &event);
#pragma endregion

  virtual bool on_audio_device_added(const SDL_Event &event);
  virtual bool on_audio_device_removed(const SDL_Event &event);

  virtual bool on_render_targets_reset(const SDL_Event &event);
  virtual bool on_render_device_reset(const SDL_Event &event);

  // virtual bool on_poll_sentinel(const SDL_Event &event);

  // virtual bool on_user_event(const SDL_Event &event);
};
