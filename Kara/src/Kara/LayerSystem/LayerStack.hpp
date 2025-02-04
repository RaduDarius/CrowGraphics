#pragma once

#include "Kara/Core/Core.hpp"

namespace Kara {
namespace LayerSystem {
class Layer;

class KARA_API LayerStack {
  using Container = std::vector<Layer *>;

public:
  ~LayerStack();

  //! @brief Used to insert a layer to the layer stack. Caller will lose
  //! ownership over the [aLayer] parameter
  void Push(Layer *aLayer);
  void Pop(Layer *aLayer);

  //! @brief Used to insert an overlay to the layer stack. Caller will lose
  //! ownership over the [aLayer] parameter
  void PushOverlay(Layer *aLayer);
  void PopOverlay(Layer *aLayer);

  void map(const std::function<void(Layer *)> &aFunc);
  void mapi(const std::function<bool(Layer *)> &aFunc);

private:
  Container mLayers;
  Container mOverlays;
};
} // namespace LayerSystem
} // namespace Kara