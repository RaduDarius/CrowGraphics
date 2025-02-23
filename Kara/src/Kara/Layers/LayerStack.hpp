#pragma once

#include "Kara/Core/Core.hpp"

namespace Kara {
namespace Layers {
class Layer;

class LayerStack {
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

  //! @brief Calls a function on every layer and overlay from the LayerStack,
  //! starting with the layers.
  //! @param aFunc should receive a Layer and return nothing
  void map(const std::function<void(Layer *)> &aFunc);

  //! @brief Calls a function on every layer and overlay but in invers order,
  //! starting with the overlays.
  //! @param aFunc should receive a layer and return a bool which will be used
  //! in case the caller does not want to call the func on all layers/overlays.
  void mapi(const std::function<bool(Layer *)> &aFunc);

private:
  Container mLayers;
  Container mOverlays;
};
} // namespace Layers
} // namespace Kara