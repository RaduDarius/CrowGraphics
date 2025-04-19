#pragma once

#include "Kara/Core/Core.hpp"
#include "Kara/Graphics/Material.hpp"
#include "Kara/Graphics/Types.hpp"
#include "Kara/Graphics/VertexArray.hpp"

namespace Kara {
namespace Graphics {
class RenderBatcher2D {
  using Map = std::unordered_map<Core::Ref<Material>,
                                 std::vector<Core::Ref<VertexArray>>>;

public:
  inline const Map &GetBatches() const { return mBatches; }

  void Clear() { mBatches.clear(); }
  void SubmitQuad(const Quad &aQuad, const Core::Ref<Material> aMaterial);

private:
  Core::Ref<VertexArray> ConstructVertexArray(const Quad &aQuad) const;

  Map mBatches;
};
} // namespace Graphics
} // namespace Kara